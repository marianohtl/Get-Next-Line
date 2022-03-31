/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmariano <tmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:11:15 by tmariano          #+#    #+#             */
/*   Updated: 2022/03/30 22:08:49 by tmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);

#endif
