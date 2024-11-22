/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:05:03 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/21 15:05:03 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:48:35 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/20 09:48:35 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
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
void update_list_v2(t_list **head, int len, t_list *new_head, char *remaining)
{
	t_list *tmp;

	while (*head && len > 0)
	{
		tmp = (*head)->next;
		if (len >= ft_strlen((*head)->content))
		{
			len -= ft_strlen((*head)->content);
			free((*head)->content);
			free(*head);
			*head = tmp;
		}
		else
		{
			remaining = ft_strdup((*head)->content + len);
			free((*head)->content);
			return (((*head)->content) = remaining, *head);
		}
	}
	return (*head);
}
