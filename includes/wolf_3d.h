/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 07:08:46 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/06 16:28:11 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
#define WOLF_3D_H

# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
#include "../libft/libft.h"

typedef struct	s_env
{
	void		*window;
	void		*mlx;
}				t_env;

typedef struct	s_rows
{
	int			rows;
	int			columns;
}				t_rows;

typedef struct	s_variables
{
	char		**array;
}				t_variables;

int				keys(int keycode);
char			**read_from_file(int fd);
char			*create_file_content(char *curr, char *to_add, size_t rsize);
t_rows			size(int fd);
#endif
