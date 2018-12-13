/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:05:40 by magrinbe          #+#    #+#             */
/*   Updated: 2018/12/13 19:45:30 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*buff;
	char	ch;
	int		i = 0;
	
	fd = open("test.txt", O_RDONLY);

	get_next_line(fd, &buff);
	// ft_putstr(buff);
	// ft_putchar('\n');
	// get_next_line(fd, &buff);
	// ft_putstr(buff);
	// ft_putchar('\n');
	// get_next_line(fd, &buff);
	// ft_putstr(buff);
	// ft_putchar('\n');
	// get_next_line(fd, &buff);
	// ft_putstr(buff);
	// ft_putchar('\n');
	// get_next_line(fd, &buff);
	// ft_putstr(buff);
	// ft_putchar('\n');
	// get_next_line(fd, &buff);
	// ft_putstr(buff);
	// ft_putchar('\n');
	// get_next_line(fd, &buff);
	// ft_putstr(buff);
	// ft_putchar('\n');
	// get_next_line(fd, &buff);
	// ft_putstr(buff);

	return (0);
}
