/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:13:23 by magrinbe          #+#    #+#             */
/*   Updated: 2018/12/20 22:25:20 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_buffer(int const fd, char *tmp)
{
	ssize_t		j;

 	j = read(fd, tmp, BUFF_SIZE);
	return (j);
}

static char		*stock_buffer(int const fd, char **buffer)
{
	ssize_t		j;
	char	tmp[BUFF_SIZE + 1];
	int stop;

 	while ((stop == 0) && j > 0)
	{
	j = read_buffer(fd, tmp);
	buffer = ft_strjoin(buffer, tmp);
	if (ft_strstr(tmp, "\n"))
		stop = 1;
	ft_bzero(tmp, BUFF_SIZE);
	}
	return (buffer);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buff = NULL;
	char  tmp[BUFF_SIZE + 1];
	ssize_t		j;

	if (BUFF_SIZE <= 0 || fd < 0 || line == NULL || (read(fd, &r, 0) == -1))
		return (-1);
	*line = NULL;
	if (!buff)
		buff = ft_strnew(1);
	buff = stock_buffer(fd, buff);
}