/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:40:14 by conrodri          #+#    #+#             */
/*   Updated: 2020/02/20 18:57:13 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	size_t	k;
	char	*dest;

	i = 0;
	k = 0;
	if (s != NULL)
	{
		len = ft_strlen(s);
		if (ft_strlen(s) == 0)
			return (ft_strnew(0));
		while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
			len--;
		while (s[k] == ' ' || s[k] == '\t' || s[k] == '\n')
		{
			k++;
			if (s[k] == '\0')
				return (ft_strnew(0));
		}
		dest = ft_strsub(s, k, len - k);
		return (dest);
	}
	return (NULL);
}
