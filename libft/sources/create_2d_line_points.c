/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_2d_line_points.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:39:25 by qpupier           #+#    #+#             */
/*   Updated: 2020/02/20 18:57:20 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_2d_line	create_2d_line_points(t_real p1, t_real p2)
{
	float	a;
	float	tmp;

	if (!(tmp = p2.x - p1.x))
		return ((t_2d_line){1, 0, -p1.x});
	a = (p2.y - p1.y) / tmp;
	return ((t_2d_line){a, -1, p1.y - p1.x * a});
}
