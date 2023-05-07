#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("texto", O_RDONLY);
	char *line_1 = get_next_line(fd);
	char	*line2 = get_next_line(fd);
	
	printf("%s", line_1);
	printf("%s", line2);
	free(line_1);
	free(line2);
	close(fd);
	return 0;
}