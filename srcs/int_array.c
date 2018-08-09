/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 08:42:31 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/08 08:42:39 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

char     **make_int_array(t_env env, t_rows d)
{
    char     **tab;
    int     i;
    int     n;

    n = 0;
    tab = (char **)malloc(sizeof(char*) * (d.rows * d.columns + 1));
    while (env.points && n < d.rows)
    {
        i = 0;
        tab[n] = (char *)malloc(sizeof(char) * (d.columns + 1));
        while (i < d.columns)
        {
            tab[n][i] = env.points->z;
            env.points = env.points->next;
            i++;
        }
        tab[n][i] = '\0';
        n++;
    }
    tab[n] = NULL;
    return (tab);
}