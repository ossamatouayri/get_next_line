/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:24:06 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/18 16:24:06 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int len_to_newline(t_list *lst)
{
	int i;
	int len;

	if (!lst)
		return (0);
	len = 0;
	while(lst)
	{
		i = 0;
		while(lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		lst = lst->next;
	}
	return(len);
}

void copy_str(t_list *lst, char *next_string)
{
	int i;
	int j;

	if (!lst)
		return ;
	i = 0;
	while(lst)
	{
		j = 0;
		while(lst->content[i])
		{
			if(lst->content[i] == '\n')
			{
				next_string[j++] = '\n';
				next_string[j] = '\0';
				return ;
			}
			next_string[j++] = lst->content[i++];
		}
		lst = lst->next;
	}
	next_string[j] = '\0';
}

void clear_nodes(t_list **list, t_list *clean_node, char *buff)
{
	t_list *tmp;

	while(*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
	*list == NULL;
	if (clean_node->content[0])
		*list = clean_node;
	else
	{
		free(buff);
		free(clean_node);
	}
}
t_list *find_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while(list->next)
	{
		list = list->next;
	}
	return (list);
}

int found_newline(t_list *lst)
{
	int i;
	if (!lst)
		return (0);
	i = 0;
	while(lst)
	{
		i = 0;
		while(lst->content[i] != '\0' && i < BUFFER_SIZE)
		{
			if (lst->content[i] == '\n')
				return (0);
			++i;
		}
		lst  = lst->next;
	}
	return (0);
}
