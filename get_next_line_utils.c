
#include "get_next_line.h"
#include <string.h>
void append(t_list **list, char *buf)
{
    t_list *new;
    t_list *node;
    

    new = malloc(sizeof(t_list));
    if (!new)
        return; // Verifique falhas de alocação
    new->buf = strdup(buf); // Copia o conteúdo de buf para um novo buffer
    new->next = NULL;

    if (*list == NULL)
    {
        *list = new;
    }
    else
    {
        node = *list;
        while (node->next)
            node = node->next;
        node->next = new;
    }
}
char *copy(t_list **list)
{
    t_list  *node = *list;
    t_list  *init = node;
    char *str;
    int i = 0;
    int j = 0;

    while (node)
    {
        while(node->buf[i])
        {
            j++;
            i++;
        }
        i = 0;
        node = node->next;
    }
    str = malloc(j + 1);
    j = 0;
    i = 0;
    while (init)
    {
         while(init->buf[j])
        {
            str[i] = init->buf[j];
            i++;
            j++;
        }
        j = 0;
        init = init->next;
    }
    str[i] = '\0';
    return str;
}

char    *create_list(t_list **list, int fd)
{
    int bytes_read;
    char buf[BUFFER_SIZE + 1];

    while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
    {

         buf[bytes_read] = '\0';
          append(list, buf);
    }
    return copy(list);
}

