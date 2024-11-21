/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardoso <jcardoso@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:41:13 by jcardoso          #+#    #+#             */
/*   Updated: 2024/11/21 12:41:13 by jcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_list(t_list **list)
{
	t_list				*last_node;
	t_list				*clean_node;
	int					i;
	int					j;
	char				*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->buf[i] && last_node->buf[i] != '\n')
		i++;
	while (last_node->buf[i] && last_node->buf[++i])
		buf[j++] = last_node->buf[i];
	buf[j] = '\0';
	clean_node->buf = buf;
	clean_node->next = NULL;
	free_list(list, clean_node, buf);
}

char	*get_line(t_list *list)
{
	char	*str;
	int		str_len;

	if (list == NULL)
		return (NULL);
	str_len = index_newline(list);
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	copy_str(list, str);
	return (str);
}

void	ft_lstadd_back(t_list **lst, char *buf)
{
	t_list	*new;
	t_list	*last_node;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	last_node = find_last_node(*lst);
	if (*lst == NULL)
		*lst = new;
	else
		last_node->next = new;
	new->buf = buf;
	new->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	char	*buf;
	int		bytes;

	while (!found_newline(*list))
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (!bytes)
		{
			free(buf);
			return ;
		}
		buf[bytes] = '\0';
		ft_lstadd_back(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line(list);
	clean_list(&list);
	return (next_line);
}
