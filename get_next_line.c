#include<fcntl.h>
#include<unistd.h>
#include"libft.h"

char *get_next_line(int fd){
	static char butter[16];
	char *butter_last;
	char butter_other[17];
	size_t menino;
	static int i;
	butter_last = "";
	while (butter[i] != '\n')
	{
		if(i == 15)
		{
			 ft_strlcpy(butter_other,butter, 17);
			butter_last = ft_strjoin(butter_last, butter_other);
			read(fd, butter, 16);
			i = 0;
		}else{
			i++;
		}
	}
	ft_strlcpy(butter_other,butter, i + 2);
	butter_last = ft_strjoin(butter_last, butter_other);
	i++;
	return butter_last;
}
int main(){
	int fd = open("README.md", O_RDONLY);
	char *result;

	result = get_next_line(fd);
	result = get_next_line(fd);
	result = get_next_line(fd);
	result = get_next_line(fd);
	result = get_next_line(fd);

	return 0;
}
