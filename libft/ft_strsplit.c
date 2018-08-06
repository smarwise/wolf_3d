/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 09:19:49 by smarwise          #+#    #+#             */
/*   Updated: 2018/06/08 17:20:52 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		word_count(const char *s, char c)
{
	size_t i;
	size_t wdcount;

	i = 0;
	wdcount = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			return (wdcount);
		while (s[i] != c && s[i])
			i++;
		wdcount++;
	}
	return (wdcount);
}

static char			**ft_oneword(char **tab, char c, const char *s, int t)
{
	int				len;
	int				i;

	i = 0;
	len = ft_strlen(s);
	len--;
	while (s[i] && s[i] == c)
		i++;
	while (s[len] == c)
		len--;
	tab[t] = ft_strsub(s, i, len - i + 1);
	t++;
	tab[t] = NULL;
	return (tab);
}

static char			**ft_split(char **tab, char c, int t, char *str)
{
	int				cmp;
	int				i;

	i = 0;
	cmp = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		cmp = i;
		if (str[i] == '\0')
		{
			tab[t] = NULL;
			return (tab);
		}
		while (str[i] && str[i] != c)
			i++;
		tab[t] = ft_strsub(str, cmp, i - cmp);
		t++;
	}
	tab[t] = NULL;
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	char			*str;
	int				t;

	t = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)s;
	tab = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	if (word_count(s, c) == 1)
		return (ft_oneword(tab, c, s, t));
	return (ft_split(tab, c, t, str));
}
