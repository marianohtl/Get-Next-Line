/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmariano <tmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:11:15 by tmariano          #+#    #+#             */
/*   Updated: 2022/03/30 22:10:02 by tmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strjoin(char *s1, char *s2, size_t n)
{
	char	*concat;

	concat = malloc(n * sizeof(*concat));
	if (concat == NULL)
		return (concat);
	ft_strlcpy(concat, s1, n);
	ft_strlcat(concat, s2, n);
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

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	size;

	size = ft_strlen(s) + 1;
	result = malloc(size * sizeof(*result));
	if (result == NULL)
		return (result);
	ft_strlcpy(result, s, size);
	return (result);
}
