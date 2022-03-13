#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


char *get_next_line(int fd){

	static char butter[BUFFER_SIZE];
	static int read_bytes = -1;
	int i;
	int start_index;
	char *butter_last;
	char butter_other[BUFFER_SIZE+1];

	butter_last = "";
	while(read_bytes != 0)
	{
		read_bytes = read(fd, butter, BUFFER_SIZE);
		i = 0;
		while (i < read_bytes)
		{
			if (butter[i] == '\n')
			{
				ft_strlcpy(butter_other, &butter[0], i - 0 + 2);
				butter_last = ft_strjoin(butter_last, butter_other);
				return(butter_last);
			}
			i++;
		}
	}
	read_bytes = -1;
	return (NULL);
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