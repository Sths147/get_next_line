#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*result;
	int		fd;

	fd = open("explain.txt", O_RDONLY);
	while (1)
	{
		result = get_next_line(fd);
		if (!result)
			break;
		printf("%s", result);
		free(result);
	}
	close(fd);
}