/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:52:27 by qpupier           #+#    #+#             */
/*   Updated: 2020/02/20 18:55:40 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_real	real_turn(t_real point, float degree)
{
	t_real	new;

	degree = ft_deg_to_rad(degree);
	new.x = cos(degree) * point.x - sin(degree) * point.y;
	new.y = sin(degree) * point.x + cos(degree) * point.y;
	return (new);
}
