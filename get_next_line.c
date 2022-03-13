#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


char *get_next_line(int fd)
{
	static char butter[16];
	static int start_index;
	static int i;
	static int read_bytes = 1;
	char *butter_last;
	char butter_other[17];
	size_t menino;
	butter_last = "";

	while (butter[i] != '\n' )
	{
		if (i == 15)
		{
			ft_strlcpy(butter_other, &butter[start_index], 17 - start_index);
		butter_last = ft_strjoin(butter_last, butter_other);
			read_bytes = read(fd, butter, 16);
			start_index = 0;
			i = 0;
		}
		else
		{
			i++;
		}
	}
	ft_strlcpy(butter_other, &butter[start_index], i - start_index + 2);
	butter_last = ft_strjoin(butter_last, butter_other);
	i++;
	start_index = i;
	if(read_bytes == 0)
		return(NULL);
	return butter_last;
}
int main()
{
	int fd;
	char *result;
	// fd = open("test.md", O_RDONLY);
	fd = 1;

	result = "";

	while(result != NULL)
	{
		result = get_next_line(fd);
		printf("################ inicio\n");
		printf("%s", result);
		printf("\n################ fim\n");

	}
	return 0;
}
