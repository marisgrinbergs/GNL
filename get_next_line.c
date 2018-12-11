/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:54:36 by magrinbe          #+#    #+#             */
/*   Updated: 2018/12/11 21:04:47 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_searchn(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (-1);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	ssize_t		j;
	static int	last;
	static char	*buff = "";
	char 		tmp[BUFF_SIZE + 1];
	static int pos;
	int			stop;
	static int	start;

	stop = 0;
	if (fd < 0 || fd > 4864)
		return (-1);
	while ((stop == 0) && (j = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		buff = ft_strjoin(buff, tmp);
		if (ft_searchn(tmp) == -1)
		{
			stop = 1;
		}
	}
	while (buff[pos] && buff[pos] != '\n')
		pos++;
	*line = ft_strsub(buff, start, pos - start);
	start = pos + 1;
	pos++;
	if (j > 0)
		return (1);
	if (j == 0 && last == 0)
	{
		last = 1;
		return (1);
	}
	if (j == -1)
		return (-1);
	return (0);
}
