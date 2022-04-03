/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmariano <tmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:11:15 by tmariano          #+#    #+#             */
/*   Updated: 2022/04/01 00:51:38 by tmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE -1
#endif

static ssize_t	ft_strchri(const char *string, int c)
{
	ssize_t	index;
	char	convert_c;

	convert_c = (char) c;
	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == convert_c)
			return (index);
		index++;
	}
	if (string[index] == convert_c)
		return (index);
	return (-1);
}

static char	*cleaning(char **old_adress, char *new_adress)
{
	char	*clean;

	clean = *old_adress;
	*old_adress = new_adress;
	free(clean);
	return (*old_adress);
}

static char	*tatakae(int fd, char *buffer)
{
	size_t	i;

	i = 0;
	if ((fd < 0) || (BUFFER_SIZE < 1) || (read(fd, buffer, 0) < 0))
		return (NULL);
	if (!buffer)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
		if (!buffer)
			return (NULL);
		while (i <= BUFFER_SIZE)
		{
			buffer[i] = '\0';
			i++;
		}
	}
	return (buffer);
}

static char	*new_line(char **buffer, char **next, int has_new_line,
	int read_bytes)
{
	cleaning(next, join(*next, *buffer,
			len(*next) + has_new_line + 2));
	if (!*next)
		return (NULL);
	ft_strlcpy(*buffer, &(*buffer)[has_new_line + 1],
		read_bytes - (size_t)has_new_line);
	return (*next);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next;
	size_t		read_bytes;
	int			has_new_line;

	buffer = tatakae(fd, buffer);
	if (!buffer)
		return (NULL);
	read_bytes = BUFFER_SIZE;
	next = malloc(sizeof(*next));
	if (!next)
		return (NULL);
	next[0] = '\0';
	while (read_bytes >= BUFFER_SIZE)
	{
		if (len(buffer) == 0)
			read_bytes = read(fd, buffer, BUFFER_SIZE);
		has_new_line = ft_strchri(buffer, '\n');
		if (has_new_line != -1)
			return (new_line(&buffer, &next, has_new_line, read_bytes));
		if (!(cleaning(&next, join(next, buffer, len(next) + read_bytes + 1))))
			return (NULL);
		buffer[0] = '\0';
	}
	cleaning(&buffer, NULL);
	if (*next == '\0')
		cleaning(&next, NULL);
	return (next);
}

// int main()
// {
// 	int fd = open("test.md", O_RDONLY);

// 	char *result;

// 	while(result != NULL)
// 	{
// 		result = get_next_line(fd);
// 	}
// 	return 0;
// }