/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardoso <jcardoso@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:56:13 by jcardoso          #+#    #+#             */
/*   Updated: 2024/11/25 16:33:32 by jcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*buf;
	struct s_list	*next;
}				t_list;

int		found_newline(t_list *list);
t_list	*find_last_node(t_list *list);
char	*get_line(t_list *list);
void	copy_str(t_list *list, char *str);
int		index_newline(t_list *list);
void	clean_list(t_list **list, int fd);
char	*get_next_line(int fd);
void	free_list(t_list **list, t_list *clean_node, char *buf, int fd);
void	create_list(t_list **list, int fd);

#endif
