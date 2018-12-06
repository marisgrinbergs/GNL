/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:54:36 by magrinbe          #+#    #+#             */
/*   Updated: 2018/12/06 18:15:25 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int			j;
	ssize_t		i;
	static int	last;
	static char *buff;
	char		*tmp;
	char		str;

	j = 0;
	buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	tmp = (char*)malloc(sizeof(char) * 10000);
	if (fd < 0 || fd > 4864)
		return (-1);
	while ((i = read(fd, buff, BUFF_SIZE)))
	{
		buff[BUFF_SIZE] = '\0';
		while (buff[j] && buff[j] != '\n')
		{
			tmp[j] = buff[j];
			j++;
		}
		tmp[j] = '\0';
	}
	*line = tmp;
	if (i > 0)
		return (1);
	if (i == 0 && last == 0)
	{
		last = 1;
		return (1);
	}
	if (i == -1)
		return (-1);
	return (0);
}
