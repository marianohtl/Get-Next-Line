#include "get_next_line.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_src;
	size_t	size_dest;

	size_src = ft_strlen(src);
	size_dest = ft_strlen(dest);
	if (size <= size_dest)
		return (size_src + size);
	ft_strlcpy(&dest[size_dest], src, size - size_dest);
	return (size_dest + size_src);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				index;
	unsigned char		*str_dest;
	const unsigned char	*str_src;

	str_dest = dest;
	str_src = src;
	index = 0;
	while (index < n)
	{
		str_dest[index] = str_src[index];
		index = index + 1;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_length;
	size_t	copy_length;

	src_length = ft_strlen(src);
	if (size != 0)
	{
		copy_length = src_length;
		if (size <= src_length)
			copy_length = size - 1;
		ft_memcpy(dest, src, copy_length);
		dest[copy_length] = '\0';
	}
	return (src_length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		all_size;

	all_size = ft_strlen(s1);
	all_size += ft_strlen(s2);
	concat = malloc((all_size + 1) * sizeof(*concat));
	if (concat == NULL)
		return (concat);
	ft_strlcpy(concat, s1, all_size + 1);
	ft_strlcat(concat, s2, all_size + 1);
	return (concat);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != 0)
		length++;
	return (length);
}

char	*ft_strchr(const char *string, int c)
{
	unsigned int	index;
	char			convert_c;

	convert_c = (char) c;
	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == convert_c)
			return ((char *) &string[index]);
		index++;
	}
	if (string[index] == convert_c)
		return ((char *) &string[index]);
	return (NULL);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((unsigned char *)s)[index] = c;
		index++;
	}
	return (s);
}