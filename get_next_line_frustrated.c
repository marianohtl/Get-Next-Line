#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


char *get_next_line(int fd)
{
	static char butter[BUFFER_SIZE];
	static int start_index;
	static int i;
	static int read_bytes;
	char *butter_last;
	char butter_other[BUFFER_SIZE + 1];
	size_t menino;
	butter_last = "";

	if(read_bytes == 0)
	{
		read_bytes = read(fd, butter, BUFFER_SIZE);
		if(read_bytes == 0)
			return(NULL);
	}
	while (butter[i] != '\n' )
	{
		if (i == 15)
		{
			ft_strlcpy(butter_other, &butter[start_index], BUFFER_SIZE + 1 - start_index);
			butter_last = ft_strjoin(butter_last, butter_other);
			read_bytes = read(fd, butter, BUFFER_SIZE);
			start_index = 0;
			i = 0;
			if(read_bytes == 0)
				break;
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
	return butter_last;
}
int main()
{
	int fd;
	char *result;
	fd = open("test.md", O_RDONLY);
	//fd = 1;

	result = "";

	printf("################ inicio\n");
	while(result != NULL)
	{
		result = get_next_line(fd);
		printf("%s", result);
	}
	printf("\n################ fim\n");
	return 0;
}
