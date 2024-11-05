
#include "get_next_line.h"

char *get_next_line(int fd)
{
	static t_list *list;
	char *next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0))
		return (NULL);

	next_line = create_list(&list, fd);
	while(list)
		list = list->next;
	return (next_line);
}

int main()
{
    int fd = open("fd.txt", O_RDONLY);
	int i = 0;
	while(i++<6)
    	printf("%s" ,get_next_line(fd));
    return (0);
}