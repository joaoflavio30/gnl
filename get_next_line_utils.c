
#include "get_next_line.h"
#include <string.h>

char	*ft_strchr(const char *str, int search_str)
{
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		if (*str == (unsigned char)search_str)
			return ((char *)str);
		str++;
	}
	if (*str == (unsigned char)search_str)
		return ((char *)str);
	return (NULL);
}
t_list	*ft_lstnew(char *content)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->buf = strdup(content);
	node->next = NULL;
	return (node);
}

t_list	*find_last_node(t_list *list)
{
	while(list->next)
		list = list->next;
	return (list);
}
void	ft_lstadd_back(t_list **lst, char *buf)
{
	t_list	*new;
	t_list	*last_node;

	new = ft_lstnew(buf);
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last_node = find_last_node(*lst);
		last_node->next = new;
	}
}

void	free_list(t_list **list, t_list *new_node, char* buf)
{
	t_list	*temp;
	while(*list)
	{
		temp = (*list)->next;
		free((*list)->buf);
		free((*list));
		(*list) = temp;
	}
	if (new_node->buf[0])
		(*list) = new_node;
	else
	{
		free(buf);
		free(new_node);
	}
}

void	clean_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	char	*buf;
	int		i;
	int		j;

	buf = strdup((*list)->buf);
	clean_node = malloc(sizeof(t_list));
	last_node = find_last_node(*list);

	i = 0;
	j = 0;
	while(last_node->buf[i] && last_node->buf[i] != '\n')
		i++;
	while(last_node->buf[i] && last_node->buf[++i])
		buf[j++] = last_node->buf[i];
	buf[j] = '\0';
	clean_node->buf = buf;
	clean_node->next = NULL;
	free_list(list, clean_node, buf);
}

int	index_newline(t_list *list)
{
	int	i;
	int j;

	j = 0;
	while(list)
	{
		i = 0;
		while(list->buf[i])
		{
			if (list->buf[i] == '\n')
			{
				i++;
				return (i);
			}
			i++;
			j++;
		}
		list = list->next;
	}
	return (i);
}

void	copy_str(t_list *list, char *str)
{
	int	i;
	int j;

	j = 0;
	while(list)
	{
		i = 0;
		while(list->buf[i])
		{
			if (list->buf[i] == '\n')
			{
				str[j] = list->buf[i];
				str[++j] = '\0';
				return ;
			}
			str[j] = list->buf[i];
			i++;
			j++;
		}
		list = list->next;
	}
}

char	*get_line(t_list *list)
{
	char *str;
	int	str_len;

	str_len = index_newline(list);
	str = malloc(str_len + 1);

	copy_str(list, str);
	return (str);
}

void	create_list(t_list **list, int fd)
{
	char	*buf;
	int		bytes;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return ;
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if(buf == NULL)
			return ;
		buf[bytes] = '\0';
		ft_lstadd_back(list, buf);
		if(ft_strchr(buf, '\n'))
			break;
	}
}

