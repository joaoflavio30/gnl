#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list {
    char *buf;
    struct s_list *next;
} t_list;

void    create_list(t_list **list, int fd);
char    *get_line(t_list *list);
void    free_list(t_list **list, t_list *new_node, char *buf);
void    clean_list(t_list **list);

#endif
