#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include<stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
#endif