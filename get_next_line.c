#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

char *get_next_line(int fd)
{
	static char butter[16];
	char *butter_last;
	char butter_other[17];
	size_t menino;
	static int i;
	static int start_index;
	static int read_bytes = 1;

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
		return(ft_strdup(""));
	return butter_last;
}
int main()
{
	int fd = open("test.md", O_RDONLY);
	char *result;

	result = get_next_line(fd);
	dprintf(1, "fora da funcao %s \n", result);

	result = get_next_line(fd);
	dprintf(1, "fora da funcao %s \n", result);

	result = get_next_line(fd);
	dprintf(1, "fora da funcao %s \n", result);

	result = get_next_line(fd);
	dprintf(1, "fora da funcao %s \n", result);

	result = get_next_line(fd);
	dprintf(1, "fora da funcao %s \n", result);

	result = get_next_line(fd);
	dprintf(1, "fora da funcao %s \n", result);

	result = get_next_line(fd);
	dprintf(1, "fora da funcao %s \n", result);

	result = get_next_line(fd);
	dprintf(1, "fora da funcao %s \n", result);

	result = get_next_line(fd);
	dprintf(1, "fora da funcao %s \n", result);

	result = get_next_line(fd);
	dprintf(1, "fora da funcao %s \n", result);

	result = get_next_line(fd);
	dprintf(1, "fora da funcao %s \n", result);

	return 0;
}
