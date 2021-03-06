/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_scale_product.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:35:11 by qpupier           #+#    #+#             */
/*   Updated: 2020/02/20 18:55:39 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

float	real_scale_product(t_real p1, t_real p2)
{
	return (p1.x * p2.x + p1.y * p2.y);
}
