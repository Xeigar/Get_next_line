#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("texto", O_RDONLY);
	char *line_1;
	int i = 0;
	
	while (i < 4)
	{
		line_1 = get_next_line(fd);
		printf("%s", line_1);
		free(line_1);
		i++;
	}
	close(fd);
	return 0;
}