/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:01:38 by magrinbe          #+#    #+#             */
/*   Updated: 2018/12/11 20:08:08 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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