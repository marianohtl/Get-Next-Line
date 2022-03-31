/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmariano <tmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:11:15 by tmariano          #+#    #+#             */
/*   Updated: 2022/03/30 22:46:54 by tmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

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

static void cleaning(char **old_adress, char *new_adress)
{
	char *clean;
	clean = *old_adress;
	*old_adress = new_adress;
	free(clean);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;
	size_t		read_bytes;
	int			has_new_line;
	size_t		buffer_size;

	if ((fd < 0) || (BUFFER_SIZE < 1) || (read(fd, buffer, 0) < 0))
		return (NULL);
	if (!buffer)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	read_bytes = BUFFER_SIZE;
	has_new_line = -1;
	next_line = ft_strdup("");
	if (!next_line)
		return (NULL);
	while (has_new_line == -1 && read_bytes >= BUFFER_SIZE)
	{
		buffer_size = ft_strlen(buffer);
		if (buffer_size == 0)
			read_bytes = read(fd, buffer, BUFFER_SIZE);
		has_new_line = ft_strchri(buffer, '\n');
		if (has_new_line != -1)
		{

			cleaning(&next_line, ft_strjoin(next_line, buffer, ft_strlen(next_line) + has_new_line + 2));
			if (!next_line)
				return (NULL);
			ft_strlcpy(buffer, &buffer[has_new_line + 1], read_bytes - (size_t)has_new_line);
			return (next_line);
		}
		cleaning(&next_line, ft_strjoin(next_line, buffer, ft_strlen(next_line) + read_bytes + 1));
		if (!next_line)
			return (NULL);
		buffer[0] = '\0';
	}
	cleaning(&buffer, NULL);
	if (*next_line == '\0')
	{
		free(next_line);
		return (NULL);
	}
	return (next_line);
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