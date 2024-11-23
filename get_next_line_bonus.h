/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:44:38 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/21 17:44:38 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	get_list(t_list **head, int fd);
int		get_newline(t_list *head);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
int		len_to_newline(t_list *head);
void	append_list(t_list **head, char *buff);
t_list	*update_list(t_list **head);
char	*extract_lines(t_list *head);
t_list	*update_list_v2(t_list **head, int len, char *remaining);

#endif
