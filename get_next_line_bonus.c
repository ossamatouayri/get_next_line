/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:39:01 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/21 15:39:01 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	get_list(t_list **head, int fd)
{
	int		chars_reads;
	char	*buff;

	while (!get_newline(*head))
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
			break ;
	}
}

char	*extract_lines(t_list *head)
{
	char	*new_str;
	int		new_len;
	int		i;
	int		j;

	new_len = len_to_newline(head);
	new_str = malloc(new_len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (head)
	{
		j = 0;
		while (head->content[j])
		{
			if (head->content[j] == '\n')
			{
				new_str[i++] = '\n';
				return (new_str[i] = '\0', new_str);
			}
			new_str[i++] = head->content[j++];
		}
		head = head->next;
	}
	return (new_str[i] = '\0', new_str);
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
	while (current->next)
		current = current->next;
	current->next = new_node;
}

t_list	*update_list(t_list **head)
{
	char	*remaining;
	int		len;

	if (!*head)
		return (NULL);
	remaining = NULL;
	len = len_to_newline(*head);
	*head = update_list_v2(head, len, remaining);
	return (*head);
}

char	*get_next_line(int fd)
{
	static t_list	*head[1024];
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	get_list(&head[fd], fd);
	if (!head[fd])
		return (NULL);
	next_line = extract_lines(head[fd]);
	head[fd] = update_list(&head[fd]);
	return (next_line);
}
