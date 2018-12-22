/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:37:56 by magrinbe          #+#    #+#             */
/*   Updated: 2018/12/22 02:43:23 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fjoin(char *s1, char *s2, int c)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[len] != '\0')
		len++;
	if (!(str = (char*)malloc(sizeof(char) * (i + len + 1))))
		return (NULL);
	i = -1;
	len = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++len] != '\0')
		str[i + len] = s2[len];
	str[i + len] = '\0';
	if (c != 0)
		free(s1);
	return (str);
}

char	*nextline(char *buff)
{
	int pos;
	char *str;

	pos = 0;
	while (buff[pos] && buff[pos] != '\n')
		pos++;
	if (buff[pos] == '\n')
		pos++;
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(buff + pos) + 1)))
		return (NULL);
	str = ft_strcpy(str, buff + pos);
	free(buff);
	return (str);
}

char	*ft_firstline(char *buff)
{
	int pos;
	char *str;

	pos = 0;
	while (buff[pos] && buff[pos] != '\n')
		pos++;
	if (!(str = (char*)malloc(sizeof(char) * (pos + 1))))
		return (NULL);
	str[pos] = '\0';
	str = ft_strncpy(str, buff, pos);
	return (str);
}

int		ft_searchn(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		return (-1);
	else
		return (i);
}

int			get_next_line(const int fd, char **line)
{
	ssize_t		j;
	static char	*buff = "\0";
	char  tmp[BUFF_SIZE + 1];
	int		c;
	
	c = 0;
	j = 0;
	if (!line || fd < 0 || BUFF_SIZE <= 0 || read(fd, tmp, 0) < 0)
		return (-1);
	ft_bzero(tmp, BUFF_SIZE);
	tmp[BUFF_SIZE] = '\0';
	while (ft_searchn(buff) != -1 && (j = read(fd, tmp, BUFF_SIZE) > 0))
	{
		buff = ft_fjoin(buff, tmp, c++);
		ft_bzero(tmp, BUFF_SIZE);
	}
	if (c == 0)
	{
		buff = ft_fjoin(buff, "\0", c);
		c = ft_searchn(buff);
	}
	*line = ft_firstline(buff);
	buff = nextline(buff);
	return ((c != 0 || j > 0) ? 1 : j);
}