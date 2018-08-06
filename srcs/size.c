/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 08:11:15 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/06 16:27:49 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"

t_rows		size(int fd)
{
    size_t  rsize;
	t_rows	d;
    char    *new;
    char    **ret;
    char    buffer[1000];

	d.rows = 0;
	new = ft_strnew(0);
    while ((rsize = read(fd, buffer, 1000)))
    {
        new = create_file_content(new, buffer, rsize);
    }
    ret = ft_strsplit(new, '\n');
	d.columns = ft_count_words(ret[0]);
	while (ret[d.rows])
		d.rows++;
    free(new);
	free_2d_array((void**)ret);
    return (d);
}
