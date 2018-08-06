/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 08:05:23 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/06 16:27:31 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

char		*create_file_content(char *curr, char *to_add, size_t rsize)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = (char*)malloc(sizeof(char) * ft_strlen(curr) + rsize + 1);
	while (curr[i])
	{
		new[i] = curr[i];
		i++;
	}
	while (j < rsize)
	{
		new[i] = to_add[j];
		j++;
		i++;
	}
	new[i] ='\0';
	return (new);
}

char		**read_from_file(int fd)
{
	size_t	rsize;
	char 	*new;
	char	**ret;
	char	buffer[1000];

	new = (char*)malloc(sizeof(char));
	while ((rsize = read(fd, buffer, 1000)))
	{
		new = create_file_content(new, buffer, rsize);
	}
	ret = ft_strsplit(new, '\n');
	free(new);
	return (ret);
}
