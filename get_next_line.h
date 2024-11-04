#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list {
    char *buf;
    struct s_list *next;
} t_list;

char    *create_list(t_list **list, int fd);

#endif