/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 06:40:20 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/11 13:29:41 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42

# include "libft.h"

int		get_next_line(const int fd, char **line);
int		fun(char **ret, char **line, char *buffer, int fd);
int		new_line2(char **buffer, char **ret, int fd, char **line);
int		new_line(char **buffer, char **ret, int fd, char **line);
int		find_newline(char *str);

#endif
