/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:47:41 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/21 15:07:27 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

void get_list(t_list **head, int fd)
{
	int chars_reads;
	char *buff;

	while(!get_newline(*head))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return ;
		chars_reads = read(fd, buff, BUFFER_SIZE);
		if (chars_reads <= 0)
		{
			free(buff);
			return ;
		}
		buff[chars_reads] = '\0';
		append_list(head, buff);
		free(buff);
		if (get_newline(*head))
			break;
	}
}

char *extract_lines(t_list *head)
{
	char	*new_str;
	int	new_len;
	int i;
	int j;

	new_len = len_to_newline(head);
	new_str = malloc(new_len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while(head)
	{
		j = 0;
		while(head->content[j])
		{
			if (head->content[j] == '\n')
			{
				new_str[i++] = '\n';
				new_str[i] = '\0';
				return (new_str);
			}
			new_str[i++] = head->content[j++];
		}
		head = head->next;
	}

	new_str[i] = '\0';
	return (new_str);
}

void	append_list(t_list **head, char *buff)
{
	t_list	*new_node;
	t_list	*current;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = ft_strdup(buff);
	new_node->next = NULL;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while(current->next)
		current = current->next;
	current->next = new_node;
}

t_list *update_list(t_list **head)
{
	t_list *new_head;
	t_list *tmp;
	char *remaining;
	int len;

	if (!*head)
		return (NULL);
	new_head = *head;
	len = len_to_newline(*head);
	while (*head && len > 0)
	{
		tmp = (*head)->next;
		if(len >= ft_strlen((*head)->content))
		{
			len -= ft_strlen((*head)->content);
			free((*head)->content);
			free(*head);
			*head = tmp;
		}
		else
		{
			remaining =ft_strdup((*head)->content + len);
			free((*head)->content);
			((*head)->content) = remaining;
			return (*head);
		}
	}
	return (*head);
}
char *get_next_line(int fd)
{
	static t_list *head;
	char *next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_list(&head,fd);
	if (!head)
		return (NULL);
	next_line = extract_lines(head);
	head = update_list(&head);
	return (next_line);
}
int main()
{
    int fd = open("text.txt", O_RDONLY);
    char *line;

    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
