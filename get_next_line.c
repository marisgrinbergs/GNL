/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:54:36 by magrinbe          #+#    #+#             */
/*   Updated: 2018/12/13 21:50:59 by magrinbe         ###   ########.fr       */
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

int						get_next_line(const int fd, char **line)
{
	ssize_t				j;
	static t_gnl_list	list;

	list.buff = "";
	if (fd < 0 || fd > 4864)
		return (-1);
	while ((ft_searchn(list.tmp) == 0) &&
	(j = read(fd, list.tmp, BUFF_SIZE)) > 0)
	{
		list.buff = ft_strjoin(list.buff, list.tmp);
		ft_bzero(list.tmp, BUFF_SIZE);
	}
	while (list.buff[list.pos] && list.buff[list.pos] != '\n')
		list.pos++;
	*line = ft_strsub(list.buff, list.start, list.pos - list.start);
	list.start = list.pos + 1;
	list.pos++;
	if (j > 0)
		return (1);
	if (j == 0 && list.last == 0)
	{
		list.last = 1;
		return (1);
	}
	if (j == -1)
		return (-1);
	return (0);
}
