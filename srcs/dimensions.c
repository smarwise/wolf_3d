/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:15:51 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/17 14:00:04 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		error_message(void)
{
	ft_putendl("Invalid Map");
	exit(0);
}

t_rows		get_dimensions(int fd, char *temp, t_rows d)
{
	int		rsize;
	char	*new;
	char	**ret;
	char	buffer[1000];

	new = ft_strnew(0);
	while ((rsize = read(fd, buffer, 1000)))
	{
		temp = new;
		new = create_file_content(new, buffer, rsize);
		if (rsize < 0 || buffer[0] == '\0' || new[0] == '\n')
			error_message();
		free(temp);
	}
	if (ft_count_words(new) == 0)
		error_message();
	ret = ft_strsplit(new, '\n');
	d.columns = ft_count_words(ret[0]);
	while (ret[d.rows])
		d.rows++;
	free_2d_array((void**)ret);
	free(new);
	return (d);
}

t_rows		dimensions(int fd, int argc)
{
	char	*temp;
	t_rows	d;

	d.rows = 0;
	temp = NULL;
	if (argc == 1)
	{
		ft_putendl("No map to read");
		exit(0);
	}
	if (fd < 0)
	{
		ft_putendl("Map reading failed");
		exit(0);
	}
	return (get_dimensions(fd, temp, d));
}
