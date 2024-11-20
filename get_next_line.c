/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:47:41 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/20 20:44:25 by ostouayr         ###   ########.fr       */
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
		if (get_newline(*head))
			break;
	}
}
char *ft_strdup(char *str)
{
	int	i;
	char *n_str;

	i = 0;
	n_str = malloc(ft_strlen(str) + 1);
	if (!n_str)
		return (NULL);
	while(str[i])
	{
		n_str[i] = str[i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
int get_newline(t_list *head)
{
	int i;

	while(head)
	{
		i = 0;
		while(head->content[i])
		{
			if (head->content[i] == '\n')
				return (1);
			i++;
		}
		head = head->next;
	}
	return (0);
}
char *extract_lines(t_list *head)
{
	char	*new_str;
	int	new_len;
	int i;
	int j;
	
	new_len = len_to_newline(head);
	new_str = malloc(new_len + 1);
	printf("%d\n",new_len);
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
int	len_to_newline(t_list *head)
{
	int i;
	int len;

	len = 0;
	if (!head)
		return (0);
	while (head)
	{
		i = 0;
		while(head->content[i])
		{
			if (head->content[i] == '\n')
			{
				++len;
				return (len);
			}
			++len;
			++i;
		}
		head = head->next;
	}
	return (len);
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
int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}
t_list *update_list(t_list **head)
{
	t_list *new_head;
	int len;

	new_head = *head;
	len = len_to_newline(*head);
	while (*head && len > 0)
	{
		if(len >= ft_strlen((*head)->content))
		{
			len -= ft_strlen((*head)->content);
			free((*head)->content);
			free(head);
			*head = (*head)->next;
		}
		else
		{
			(*head)->content = ft_strdup((*head)->content + len);
			return (new_head); 
		}
	}
	return (*head);
}
char *get_next_line(int fd)
{
	static t_list *head;
	char *next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
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
	// int fd;
	// char *lines;
	// int line = 1;
	// fd = open("text.txt", O_RDONLY);
	// printf("files descriptor is : %d\n",fd);
	// lines = get_next_line(fd);
	// printf("%s\n",lines);
	// lines = get_next_line(fd);
	printf("%p",NULL);
}
