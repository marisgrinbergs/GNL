/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:37:56 by magrinbe          #+#    #+#             */
/*   Updated: 2018/12/11 19:38:05 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	ssize_t		j;
	static int	last;
	static char	*buff;
	static char tmp[BUFF_SIZE + 1];
	static int pos;
	int			stop;
	static int	start;

	stop = 0;
	if (fd < 0 || fd > 4864)
		return (-1);
	while ((j = read(fd, tmp, BUFF_SIZE)) > 0 && (stop == 0))
	{
		buff = ft_strjoin(buff, tmp);
		if (ft_strstr(buff, "\n") == 0)
		{
			printf("gros test\n");
			stop = 1;
		}
	}
	printf("%d\n", stop);
	while (buff[pos] && buff[pos] != '\n')
		pos++;
	*line = ft_strsub(buff, start, pos - 1);
	start = pos + 1;
	pos++;
	// if (j > 0)
	// 	return (1);
	// if (j == 0 && last == 0)
	// {
	// 	last = 1;
	// 	return (1);
	// }
	// if (j == -1)
	// 	return (-1);
	return (0);
}
