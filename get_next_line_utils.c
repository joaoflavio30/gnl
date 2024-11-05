
#include "get_next_line.h"
#include <string.h>

t_list	*ft_lstnew(char *content)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->buf = content;
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

void append(t_list **list, char *buf)
{
    t_list *new;
    int i = 0;

    new = malloc(sizeof(t_list));
    if (!new)
        return;
    if (*list == NULL)
    {
        int j = 1;
        int new_line = 0;
        while(buf[i])
        {
            if(buf[i] == '\n')
            {
                new_line = 1;
               new = ft_lstnew(strndup(buf, j));
               ft_lstadd_back(list, new);
               j = 0;
            }
            j++;
            i++;
        }
        if (new_line == 0)
            new = ft_lstnew(strdup(buf));
               ft_lstadd_back(list, new);

        // *list = new;
        // new->buf = strdup(buf);
        // new->next = NULL;
        // if (backup)
        //     new->buf = ft_strjoin(backup, new->buf);
        // backup = NULL;
    }
    else
    {
          int j = 1;
        int new_line = 0;
        while(buf[i])
        {
            if(buf[i] == '\n')
            {
                new_line = 1;
               new = ft_lstnew(strndup(buf, j));
               ft_lstadd_back(list, new);
               j = 0;
            }
            j++;
            i++;
        }
        if (new_line == 0)
            new = ft_lstnew(strdup(buf));
               ft_lstadd_back(list, new);
    }
}
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

    while(node)
    {
        while(node->buf[i])
        {
            str[j++] = node->buf[i];
            if(node->buf[i] == '\n')
                break;
            i++;
        } 
        if(node->buf[i] == '\n')
                break;
        i = 0;
        node = node->next;
    }
    str[j] = '\0';
    return str;
}

char    *create_list(t_list **list, int fd)
{
    int bytes_read;
    char buf[BUFFER_SIZE + 1];
    int i;

    i = 0;
    while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
    {
         buf[bytes_read] = '\0';
          append(list, buf);
          while(buf[i])
          {
            if (buf[i] == '\n' && buf[i])
                break;
            i++;
          }
          if (buf[i] == '\n' && buf[i])
                break;
        i = 0;
    }
    return copy(list);
}

