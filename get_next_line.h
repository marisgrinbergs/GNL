/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:27:10 by magrinbe          #+#    #+#             */
/*   Updated: 2018/12/13 19:58:08 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 16

typedef struct		s_gnl_list
{
	int				last;
	char			*buff;
	char			tmp[BUFF_SIZE + 1];
	int				pos;
	int				start;
}					t_gnl_list;

int		get_next_line(const int fd, char **line);

#endif