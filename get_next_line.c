/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:06:23 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/18 21:43:23 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void append(t_list **list, char *buff)
{
	t_list *new_node;
	t_list *last_node;

	last_node = find_last_node(*list);
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
char *get_line(t_list *list)
{
	int	str_len;
	char *next_string;

	if(!list)
		return (NULL);
	str_len = len_to_newline(list);
	next_string = malloc(str_len + 1);
	if (!next_string)
		return (NULL);
	copy_str(list,next_string);
	return (next_string);
}

void clear_list(t_list **list)
{
	t_list *last_node;
	t_list *clean_node;
	int i;
	int j;
	char *buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while(last_node->content[i] != '\0' && last_node->content[i] != '\n')
		i++;
	while(last_node->content[i] != '\0' && last_node->content[++i])
		buff[++j] = last_node->content[i];
	buff[j] = '\0';
	clean_node->content = buff;
	clean_node->next = NULL;
	clear_nodes(list, clean_node, buff);
}
void creat_list(t_list **list, int fd)
{
	int	chars_read;
	char *buff;
	while (!found_newline(*list))
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
	if (!list)
		return (NULL);
	next_line = get_line(list);
	clear_list(&list);
	return (next_line);
}
int main(){
	int fd;
	int lines;
	char *line;
	fd = open("text.txt", O_RDONLY);
	while(line = get_next_line(fd))
	{
		printf("%d->%s\n",lines++,line);
	}
}
