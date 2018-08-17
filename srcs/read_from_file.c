/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:17:37 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/17 13:48:28 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

char		*create_file_content(char *curr, char *to_add, size_t rsize)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = ft_strnew(ft_strlen(curr) + rsize);
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
	new[i] = '\0';
	return (new);
}

void		check_dimensions(char **ret, t_rows d)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (ret[n])
	{
		i = i + ft_count_words(ret[n]);
		n++;
	}
	n = d.rows * d.columns;
	if (i != n)
	{
		ft_putendl("Invalid Map");
		exit(0);
	}
}

char		**read_from_file(int fd, t_rows d)
{
	int		rsize;
	char	*new;
	char	**ret;
	char	buffer[1000];
	char	*temp;

	ft_bzero(buffer, 1000);
	new = ft_strnew(0);
	while ((rsize = read(fd, buffer, 1000)))
	{
		temp = new;
		if ((rsize < 0) || buffer[0] == '\0' || (ft_isalpha(buffer[3]) == 1))
		{
			ft_putendl("Invalid Map");
			exit(0);
		}
		new = create_file_content(new, buffer, rsize);
		free(temp);
	}
	ret = ft_strsplit(new, '\n');
	check_dimensions(ret, d);
	free(new);
	return (ret);
}
