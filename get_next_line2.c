/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:37:56 by magrinbe          #+#    #+#             */
/*   Updated: 2018/12/13 19:48:06 by magrinbe         ###   ########.fr       */
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

int				get_next_line(const int fd, char **line)
{
	ssize_t		j;
	static int	last;
	static char	*buff = "";
	static char	tmp[BUFF_SIZE + 1];
	static int	pos;
	static int	start;

	if (fd < 0 || fd > 4864)
		return (-1);
	while ((ft_searchn(tmp) == 0) && (j = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		buff = ft_strjoin(buff, tmp);
		ft_bzero(tmp, BUFF_SIZE);
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