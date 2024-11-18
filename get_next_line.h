/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:43:46 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/18 10:33:19 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
# endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_list
{
	char *content;
	struct s_list *next;
}	t_list;

char	*get_next_line(int fd);

#endif