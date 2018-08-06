/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:26:49 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/05 07:26:00 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					find_newline(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int					new_line(char **buffer, char **ret, int fd, char **line)
{
	char			*tmp;

	tmp = ft_strsub(ret[fd], 0, find_newline(ret[fd]));
	*line = ft_strdup(tmp);
	tmp = ret[fd];
	ret[fd] = ft_strjoin(ret[fd] + find_newline(ret[fd]) + 1, *buffer);
	ft_strdel(buffer);
	ft_strdel(&tmp);
	return (1);
}

int					new_line2(char **buffer, char **ret, int fd, char **line)
{
	char			*tmp;

	tmp = *buffer;
	*buffer = ft_strjoin(ret[fd], tmp);
	ft_strdel(&tmp);
	*line = ft_strsub(*buffer, 0, find_newline(*buffer));
	tmp = ret[fd];
	ret[fd] = ft_strdup(ft_strchr(*buffer, '\n') + 1);
	ft_strdel(&tmp);
	ft_strdel(buffer);
	return (1);
}

int					fun(char **ret, char **line, char *buffer, int fd)
{
	int				value;
	char			*tmp;

	while ((value = read(fd, buffer, BUFF_SIZE)) > 0 || (ret[fd][0] != '\0'))
	{
		buffer[value] = '\0';
		if (ft_strchr(ret[fd], '\n') != NULL)
			return (new_line(&buffer, ret, fd, line));
		if (ft_strchr(buffer, '\n') == NULL && ft_strchr(ret[fd], '\n') == NULL)
		{
			tmp = ret[fd];
			ret[fd] = ft_strjoin(tmp, buffer);
			if (value == 0)
			{
				*line = ft_strdup(ret[fd]);
				ft_strdel(&ret[fd]);
				ft_strdel(&buffer);
				return (1);
			}
			ft_strdel(&tmp);
		}
		else
			return (new_line2(&buffer, ret, fd, line));
	}
	return (value);
}

int					get_next_line(const int fd, char **line)
{
	char			*buffer;
	static char		*ret[2147483647];
	int				value;

	if (fd < 0 || BUFF_SIZE < 1 || !line || ((!ret[fd]) && (!(ret[fd] =
						(char*)ft_memalloc(sizeof(*ret[fd]))))))
		return (-1);
	buffer = ft_strnew(BUFF_SIZE);
	value = fun(ret, line, buffer, fd);
	if (value < 0)
		return (-1);
	else if (value == 0)
		return (0);
	return (1);
}
