/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardoso <jcardoso@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:55:03 by jcardoso          #+#    #+#             */
/*   Updated: 2024/11/21 12:55:03 by jcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	found_newline(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buf[i] && i < BUFFER_SIZE)
		{
			if (list->buf[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

t_list	*find_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	copy_str(t_list *list, char *str)
{
	int	i;
	int	j;

	if (list == NULL)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->buf[i])
		{
			if (list->buf[i] == '\n')
			{
				str[j] = '\n';
				str[++j] = '\0';
				return ;
			}
			str[j++] = list->buf[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	index_newline(t_list *list)
{
	int	i;
	int	j;

	if (list == NULL)
		return (0);
	j = 0;
	while (list)
	{
		i = 0;
		while (list->buf[i])
		{
			if (list->buf[i] == '\n')
			{
				j++;
				return (j);
			}
			i++;
			j++;
		}
		list = list->next;
	}
	return (j);
}

void	free_list(t_list **list, t_list *new_node, char *buf, int fd)
{
	t_list	*temp;

	if (list[fd] == NULL)
		return ;
	while (list[fd])
	{
		temp = (list[fd])->next;
		free((list[fd])->buf);
		free(list[fd]);
		list[fd] = temp;
	}
	list[fd] = NULL;
	if (new_node->buf[0])
		list[fd] = new_node;
	else
	{
		free(buf);
		free(new_node);
	}
}
