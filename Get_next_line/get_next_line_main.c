#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>

int main(void)
{
	int fd = open("test", O_RDONLY);

	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}
