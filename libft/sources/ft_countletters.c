/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countletters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:47:31 by conrodri          #+#    #+#             */
/*   Updated: 2020/02/20 18:57:28 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_countletters(char const *s, char c, int i)
{
	int nbletters;

	nbletters = 0;
	while (s[i] != c && s[i])
	{
		nbletters++;
		i++;
	}
	return (nbletters);
}
