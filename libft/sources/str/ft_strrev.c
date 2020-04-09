/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:56:24 by conrodri          #+#    #+#             */
/*   Updated: 2020/02/20 18:57:02 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrev(char *str)
{
	int i;
	int j;
	int s;

	i = 0;
	j = 0;
	while (str[j + 1] != '\0')
		j++;
	while (i < j)
	{
		s = str[j];
		str[j] = str[i];
		str[i] = s;
		i++;
		j--;
	}
	return (str);
}
