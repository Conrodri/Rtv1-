/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 21:43:09 by conrodri          #+#    #+#             */
/*   Updated: 2020/02/20 18:56:54 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = ft_memalloc(size + 1)))
		return (NULL);
	return (dest);
}
