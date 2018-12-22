/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:05:40 by magrinbe          #+#    #+#             */
/*   Updated: 2018/12/22 01:28:04 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*line;
	int		i = 0;

	fd = open("test.txt", O_RDONLY);

int r;
// get_next_line(fd, &line);
// ft_putstr(line);

// while ((r = get_next_line(fd, &line)) > 0)
// {
// 	ft_putstr(line);
// 	ft_putchar('\n');
// 	i++;
// }

while (i < 10)
{
	r = get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');
	i++;
}

	// get_next_line(fd, &line);
	// ft_putstr(line);
	// ft_putchar('\n');
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// ft_putchar('\n');
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// ft_putchar('\n');
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// ft_putchar('\n');
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// ft_putchar('\n');
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// ft_putchar('\n');
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// ft_putchar('\n');
	// get_next_line(fd, &line);
	// ft_putstr(line);


	return (0);
}
