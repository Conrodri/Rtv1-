/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:24:54 by conrodri          #+#    #+#             */
/*   Updated: 2020/02/20 18:57:05 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	**split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	if ((tab = malloc(sizeof(char *) * (ft_countword(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			k = 0;
			tab[j] = ft_strnew(ft_countletters(s, c, i) + 1);
			while (s[i] != c && s[i])
				tab[j][k++] = s[i++];
			tab[j][k++] = '\0';
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	if (s != NULL && c != '\0')
	{
		return (split(s, c));
	}
	return (NULL);
}
