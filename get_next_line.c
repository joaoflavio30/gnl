
#include "get_next_line.h"

char *get_next_line(int fd)
{
	static t_list *list;
	char *next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0))
		return (NULL);

	create_list(&list, fd);
	if(list == NULL)
		return (NULL);
	next_line = get_line(list);
	clean_list(&list);
	return (next_line);
}

int main()
{
	char *line;
    int fd = open("fd.txt", O_RDONLY);
	while((line = get_next_line(fd)))
    	printf("%s", line);
}
