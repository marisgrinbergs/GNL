/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:05:40 by magrinbe          #+#    #+#             */
/*   Updated: 2018/12/06 18:03:37 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*buff;
	char	ch;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (0);

	get_next_line(fd, &buff);
	free(buff);
	get_next_line(fd, &buff);
	ft_putstr(buff);

	/*while (get_next_line(fd, &buff) > 0)
	{
		ft_putstr(buff);
		//ft_putchar('\n');
		free(buff);
	}*/
	free(buff);
	return (0);
}
