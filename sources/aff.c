/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:58:58 by conrodri          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/03/09 18:13:53 by conrodri         ###   ########lyon.fr   */
=======
/*   Updated: 2020/03/06 17:30:43 by Admin            ###   ########.fr       */
>>>>>>> 80c8fa4baa85a92481a273b47071002142370176
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	aff_shadows(t_rt *rtv1, t_vec pi)
{
	t_obj	obj;

	rtv1->shadow->ray_or = rtv1->pi;
	rtv1->shadow->ray_dir = rtv1->obj.light.light_pos;
	stock_intersec(rtv1, rtv1->shadow);
	obj = which_intersec(rtv1);
	if (obj.t_plane[0] > 0)
	{
		rtv1->color = div_color(rtv1->color);
		// ft_pixel_put(rtv1->mlx->win, rtv1->x, rtv1->y, rtv1->color);
	}
	if (obj.t_sphere[0] > 0)
	{
		rtv1->color = div_color(rtv1->color);
		// ft_pixel_put(rtv1->mlx->win, rtv1->x, rtv1->y, rtv1->color);
	}
	if (rtv1->obj.t_cone[0] > 0)
	{
		rtv1->color = div_color(rtv1->color);
		// ft_pixel_put(rtv1->mlx->win, rtv1->x, rtv1->y, rtv1->color);
	}
	if (obj.t_cylinder[0] > 0)
	{
		rtv1->color = div_color(rtv1->color);
		// ft_pixel_put(rtv1->mlx->win, rtv1->x, rtv1->y, rtv1->color);
	}
	ft_pixel_put(rtv1->mlx->win, rtv1->x, rtv1->y, rtv1->color);
	(void)pi;
}

void	aff_cylinder(t_rt *rtv1, t_obj obj)
{
	rtv1->pi = ft_add_vec(rtv1->rays[rtv1->x + (rtv1->y * HEIGHT)].ray_or,\
			total_vec_mult_float(rtv1->rays[rtv1->x + (rtv1->y * HEIGHT)].ray_dir,\
			obj.t_cylinder[0]));
	rtv1->l = ft_sub_vec(rtv1->obj.light.light_pos, rtv1->pi);
	rtv1->n = get_norm_cylinder(obj.cylinder[0], rtv1->pi);
	rtv1->dt = dot_product(normalize(rtv1->l), normalize(rtv1->n));
	rtv1->color = add_color(total_rgb_mult_float(\
			total_rgb_mult_float((t_rgb){255, 255, 255, 0}, rtv1->dt),\
			rtv1->intensity), obj.cylinder[0].color);
	rtv1->color = color_effect(rtv1->color);
	ft_pixel_put(rtv1->mlx->win, rtv1->x, rtv1->y, rtv1->color);
	aff_shadows(rtv1, rtv1->pi);
}

void	aff_sphere(t_rt *rtv1, t_obj obj)
{
	rtv1->pi = ft_add_vec(rtv1->rays[rtv1->x + (rtv1->y * HEIGHT)].ray_or,\
			total_vec_mult_float(rtv1->rays[rtv1->x + (rtv1->y * HEIGHT)].ray_dir,\
			obj.t_sphere[0]));
	rtv1->l = ft_sub_vec(rtv1->obj.light.light_pos, rtv1->pi);
	rtv1->n = get_norm_sphere(obj.sphere[0], rtv1->pi);
	rtv1->dt = dot_product(normalize(rtv1->l), normalize(rtv1->n));
	rtv1->color = add_color(total_rgb_mult_float(\
			total_rgb_mult_float((t_rgb){255, 255, 255, 0}, rtv1->dt),\
			rtv1->intensity), obj.sphere[0].color);
	rtv1->color = color_effect(rtv1->color);
	ft_pixel_put(rtv1->mlx->win, rtv1->x, rtv1->y, rtv1->color);
	aff_shadows(rtv1, rtv1->pi);
}

void	aff_cone(t_rt *rtv1, t_obj obj)
{
	rtv1->pi = ft_add_vec(rtv1->rays[rtv1->x + (rtv1->y * HEIGHT)].ray_or,\
			total_vec_mult_float(rtv1->rays[rtv1->x + (rtv1->y * HEIGHT)].ray_dir,\
			obj.t_cone[0]));
	rtv1->l = ft_sub_vec(rtv1->obj.light.light_pos, rtv1->pi);
	rtv1->n = get_norm_cone(obj.cone[0], rtv1->pi);
	rtv1->dt = dot_product(normalize(rtv1->l), normalize(rtv1->n));
	rtv1->color = add_color(total_rgb_mult_float(\
			total_rgb_mult_float((t_rgb){255, 255, 255, 0}, rtv1->dt),\
			rtv1->intensity), obj.cone[0].color);
	rtv1->color = color_effect(rtv1->color);
	ft_pixel_put(rtv1->mlx->win, rtv1->x, rtv1->y, rtv1->color);
	aff_shadows(rtv1, rtv1->pi);
}

void	aff_plane(t_rt *rtv1, t_obj obj)
{
	rtv1->pi = ft_add_vec(rtv1->rays[rtv1->x + (rtv1->y * HEIGHT)].ray_or,\
			total_vec_mult_float(rtv1->rays[rtv1->x + (rtv1->y * HEIGHT)].ray_dir,\
			obj.t_plane[0]));
	rtv1->l = ft_sub_vec(rtv1->obj.light.light_pos, rtv1->pi);
	rtv1->n = obj.plane[0].angle;
	rtv1->dt = dot_product(normalize(rtv1->l), normalize(rtv1->n));
	rtv1->color = add_color(total_rgb_mult_float(\
			total_rgb_mult_float((t_rgb){255, 255, 255, 0}, rtv1->dt),\
			rtv1->intensity), obj.plane[0].color);
	rtv1->color = color_effect(rtv1->color);
	ft_pixel_put(rtv1->mlx->win, rtv1->x, rtv1->y, rtv1->color);
	aff_shadows(rtv1, rtv1->pi);
}
