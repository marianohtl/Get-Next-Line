#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


char *get_next_line(int fd)
{
	static char *butter;
	static int start_index;
	static int i;
	static ssize_t read_bytes;
	char *butter_last;
	char *butter_other;
	char *nana;

	butter_last = ft_strdup("");
	butter_other = malloc((BUFFER_SIZE + 1) * sizeof(*butter_other));
	butter_other[0] = '\0';
	if(!butter_other)
	{
		printf("porra malloc");
		return butter_other;
	}
	if(!butter)
	{
		butter = malloc(BUFFER_SIZE * sizeof(*butter));
		if(!butter)
		{
			printf("porra malloc");
			return butter;
		}
	}

	if(read_bytes == 0)
	{
		read_bytes = read(fd, butter, BUFFER_SIZE);
		if(read_bytes == 0)
			return(NULL);
	}
	while (butter[i] != '\n')
	{
		if (i > read_bytes - 1)
		{
			ft_strlcpy(butter_other, &butter[start_index], read_bytes + 1 - start_index);
			if(!butter_other)
				return butter_other;
			nana = butter_last;
			butter_last = ft_strjoin(butter_last, butter_other);
			free(nana);
			if(!butter_last)
				return butter_last;
			//ft_memset(butter, 0, BUFFER_SIZE);
			read_bytes = read(fd, butter, BUFFER_SIZE);
			if(read_bytes < BUFFER_SIZE)
				butter[read_bytes] = 0;
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
	if(!butter_other){
		free(butter_last);
		return butter_other;
	}
	nana = butter_last;
	butter_last = ft_strjoin(butter_last, butter_other);
	free(nana);
	free(butter_other);
	if(!butter_last)
		return butter_last;
	i++;

	start_index = i;
	return butter_last;
}
