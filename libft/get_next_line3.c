/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:08:19 by magrinbe          #+#    #+#             */
/*   Updated: 2018/12/21 21:45:21 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	ssize_t		j;
	static char	*buff = "";
	static char  tmp[BUFF_SIZE + 1];
	static int pos;
	int			stop;
	static int	start;
	char		*l;
	
	stop = 0;
	j = 1;
	l = NULL;
	if (fd < 0 || fd > 4864)
		return (-1);
	while ((stop == 0) && j > 0)
	{
		j = read(fd, tmp, BUFF_SIZE);
		tmp[j] = '\0';
		buff = ft_strjoin(buff, tmp);
		if (ft_strstr(tmp, "\n"))
			stop = 1;
		ft_bzero(tmp, BUFF_SIZE);
	}
	if (buff[pos])
	{
	while (buff[pos] && buff[pos] != '\n')
		pos++;
	l = ft_strsub(buff, start, pos - start);
 	start = pos + 1;
	pos++;
	}
	*line = l;
	if (j > 0)
		return (1);
	if (l)
		return (1);
	if (j < 0)
		return (-1);
	return (0);
}