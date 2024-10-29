#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char buffer[100];
    int fd = open("fd.txt", O_RDONLY);

    size_t bytes_read;

    size_t i = 0;
    while((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
    {
        write(1, &buffer[i], bytes_read);
        i++;
    }

      buffer[bytes_read] = '\0';
    return (0);
}