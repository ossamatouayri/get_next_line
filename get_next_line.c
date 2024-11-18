/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:06:23 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/18 11:42:39 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void append(t_list **list, char buff)
{
	t_list *new_node;
	t_list *last_node;

	last_node = find_last_node(*lst);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buff;
	new_node->next = NULL;
}
void creat_list(t_list **list, int fd)
{
	int	chars_read;
	char *buff;
	while (!found_newline(&list))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return ;
		chars_read = read(fd, buff, BUFFER_SIZE);
		if (!chars_read)
		{
			free(buff);
			return ;
		}
		buff[chars_read] = '\0';
		append(list,buff);
	}
}
char *get_next_line(int fd)
{
	static t_list *list = NULL;
	char	*next_line;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,&next_line,0)< 0)
		return (NULL);
	creat_list(&list, fd);
}
