
#include "get_next_line.h"
#include <string.h>


char	*ft_strndup(const char *s, int n)
{
	size_t	s_length;
	size_t	i;
	char	*duplicate;

	s_length = strlen(s);
	i = 0;
	duplicate = (char *) malloc((s_length + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	while (*s && n > -1)
		duplicate[i++] = *s++;
	duplicate[i] = '\0';
	return (duplicate);
}

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
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		node = *lst;
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
	new->next = NULL;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int	s1_len;
	int	s2_len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	i = -1;
	s1_len = strlen(s1);
	s2_len = strlen(s2);
	str = (char *) malloc((s1_len + s2_len) + 1);
	if (!str)
		return (NULL);
	while (++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		str[s1_len++] = s2[i];
	str[s1_len] = '\0';
	return (str);
}
/* void append(t_list **list, char *line)
{
	t_list	*node =
} */

// void append(t_list **list, char *buf)
// {
//     t_list *new;
// 	static	*char backup;
//     int i = 0;

//     new = malloc(sizeof(t_list));
//     if (!new)
//         return;
//     if (*list == NULL)
//     {
//         int j = 1;
//         int new_line = 0;
//         while(buf[i] != '\n' && buf[i])
//         {
// 				if (buf[i + 1] == '\n')
// 				{
// 					new = ft_lstnew(strndup(buf, i + 1));
// 					ft_lstadd_back(list, new);
// 				}
// 				i++;
//         }
// 		while (buf[i])
// 		{
// 			while(buf[i] != '\n' && buf[i])
// 			{
// 					backup[i] = buf[i];
// 					i++;
// 			}
// 			i++;
// 		}
//     }
//     else
//     {
//           int j = 1;
//         int new_line = 0;
//         while(buf[i])
//         {
//             if(buf[i] == '\n')
//             {
//                 new_line = 1;
//                new = ft_lstnew(strndup(buf, j));
//                ft_lstadd_back(list, new);
//                j = 0;
//             }
//             j++;
//             i++;
//         }
//         if (new_line == 0)
//             new = ft_lstnew(strdup(buf));
//                ft_lstadd_back(list, new);
//     }
// }
char *copy(t_list **list)
{
   t_list   *node;
   char     *str;
   int      i;
   int      j;

    j = 0;
    i = 0;
    node = *list;
   str = malloc(1000);
	while (node->buf[i])
	{
		str[i] = node->buf[i];
		i++;
	}
    str[i] = '\0';
    return str;
}

char    *create_list(t_list **list, int fd)
{
	char	*buf;
	int		bytes;
	t_list	*node;
	int i = 0;
	int j = 0;
	char line[1024];

	node = NULL;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				line[j+1] = '\0';
				line[j] = buf[i];
				ft_lstadd_back(list, &(ft_lstnew(line)))
				j = 0;
			}
			else
			{
				line[j] = buf[i];
				j++;
			}
			i++;
		}
	}
	if (j > 0)
	{
		line[j] = '\0';
		ft_lstadd_back(list, &(ft_lstnew(line)))
	}
	return node;
}

