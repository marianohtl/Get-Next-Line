/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmariano <tmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:11:15 by tmariano          #+#    #+#             */
/*   Updated: 2022/04/06 23:54:27 by tmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

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

static char	*clean_set(char **old_adress, char *new_adress)
{
	char	*clean;

	clean = *old_adress;
	*old_adress = new_adress;
	free(clean);
	return (*old_adress);
}

static void	initialize_buff(int fd, char **buff)
{
	if ((fd < 0) || (BUFFER_SIZE < 1) || (read(fd, buff[fd], 0) < 0))
	{
		buff[fd] = NULL;
		return ;
	}
	if (!buff[fd])
	{
		buff[fd] = malloc((BUFFER_SIZE + 1) * sizeof(*buff[fd]));
		if (!buff[fd])
			return ;
		ft_strset(buff[fd], BUFFER_SIZE + 1);
	}
}

static char	*new_line(char **buff, char **next, int has_new_line,
	int rd_bytes)
{
	char	*concat;

	concat = join(*next, *buff, len(*next) + has_new_line + 2);
	clean_set(next, concat);
	if (!*next)
		return (NULL);
	ft_strlcpy(*buff, &(*buff)[has_new_line + 1],
		rd_bytes - (size_t)has_new_line);
	ft_strset(&(*buff)[rd_bytes - (size_t)has_new_line], has_new_line + 1);
	return (*next);
}

char	*get_next_line(int fd)
{
	static char	*buff[5000];
	char		*next;
	size_t		rd_bytes;
	int			has_new_line;

	initialize_buff(fd, buff);
	if (fd < 0 || !buff[fd])
		return (NULL);
	rd_bytes = BUFFER_SIZE;
	next = NULL;
	while (rd_bytes >= BUFFER_SIZE)
	{
		if (len(buff[fd]) == 0)
			rd_bytes = read(fd, buff[fd], BUFFER_SIZE);
		has_new_line = ft_strchri(buff[fd], '\n');
		if (has_new_line != -1)
			return (new_line(&buff[fd], &next, has_new_line, rd_bytes));
		if (!(clean_set(&next, join(next, buff[fd], len(next) + rd_bytes + 1))))
			return (NULL);
		ft_strset(buff[fd], BUFFER_SIZE + 1);
	}
	clean_set(&buff[fd], NULL);
	if (len(next) == 0)
		clean_set(&next, NULL);
	return (next);
}
