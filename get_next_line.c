
#include "get_next_line.h"

char *get_next_line(int fd)
{
	static t_list *list;
	char *next_line;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0))
		return (NULL);

	return (create_list(&list, fd));
}

int main()
{
    int fd = open("fd.txt", O_RDONLY);

    printf("%s\n" ,get_next_line(fd));
    return (0);
}