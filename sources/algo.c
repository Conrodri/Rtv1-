/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:59:02 by conrodri          #+#    #+#             */
/*   Updated: 2020/03/09 17:20:45 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	stock_intersec(t_rt *rtv1, t_3d_ray *rays)
{
	int i;

	i = -1;
	while ((++i < rtv1->nb_allobj))
	{
		if (i < rtv1->nb_plane)
		{
			rtv1->obj.t_plane[i] =\
			int_plane(rtv1->obj.plane[i], &rays[rtv1->x + (rtv1->y * HEIGHT)], 2000);
		}
		if (i < rtv1->nb_sphere)
		{
			rtv1->obj.t_sphere[i] =\
			int_sph(rtv1->obj.sphere[i], &rays[rtv1->x + (rtv1->y * HEIGHT)], 2000);
		}
		if (i < rtv1->nb_cylinder)
		{
			rtv1->obj.t_cylinder[i] =\
			int_cyl(rtv1->obj.cylinder[i], &rays[rtv1->x + (rtv1->y * HEIGHT)]);
		}
		if (i < rtv1->nb_cone)
		{
			rtv1->obj.t_cone[i] =\
			int_cone(rtv1->obj.cone[i], &rays[rtv1->x + (rtv1->y * HEIGHT)]);
		}
	}
}

t_obj	which_intersec(t_rt *rtv1)
{
	int i;
	float tmp1;
	float tmp2;
	float tmp3;
	float tmp4;

	i = -1;
	tmp1 = 100000;
	tmp2 = 100000;
	tmp3 = 100000;
	tmp4 = 100000;
	while (++i < rtv1->nb_allobj)
	{
		if (i < rtv1->nb_sphere)
		{
			tmp1 = rtv1->obj.t_sphere[i] < tmp1 ? rtv1->obj.t_sphere[i] : tmp1;
			rtv1->aff_obj.sphere[0] = rtv1->obj.sphere[i];
			rtv1->aff_obj.t_sphere[0] = tmp1;
		}
		if (i < rtv1->nb_cone)
		{
			tmp2 = rtv1->obj.t_cone[i] < tmp2 ? rtv1->obj.t_cone[i] : tmp2;
			rtv1->aff_obj.cone[0] = rtv1->obj.cone[i];
			rtv1->aff_obj.t_cone[0] = tmp2;
		}
		if (i < rtv1->nb_plane)
		{
			tmp3 = rtv1->obj.t_plane[i] < tmp3 ? rtv1->obj.t_plane[i] : tmp3;
			rtv1->aff_obj.plane[0] = rtv1->obj.plane[i];
			rtv1->aff_obj.t_plane[0] = tmp3;
		}
		if (i < rtv1->nb_cylinder)
		{
			tmp4 = rtv1->obj.t_cylinder[i] < tmp4 ? rtv1->obj.t_cylinder[i] : tmp4;
			rtv1->aff_obj.cylinder[0] = rtv1->obj.cylinder[i];
			rtv1->aff_obj.t_cylinder[0] = tmp4;
		}
	}
	if (tmp1 < tmp2 && tmp1 < tmp3 && tmp1 < tmp4)
		rtv1->aff_obj.name = "Sphere";
	else if(tmp2 < tmp1 && tmp2 < tmp3 && tmp2 < tmp4)
		rtv1->aff_obj.name = "Cone";
	else if (tmp3 < tmp1 && tmp3 < tmp2 && tmp3 < tmp4)
		rtv1->aff_obj.name = "Plane";
	else if(tmp4 < tmp1 && tmp4 < tmp2 && tmp4 < tmp3)
		rtv1->aff_obj.name = "Cylinder";
	else 
		rtv1->aff_obj.name = "Nothing";
	return(rtv1->aff_obj);
}

void		aff_form(t_rt *rtv1)
{
	stock_intersec(rtv1, rtv1->rays);
	rtv1->aff_obj = which_intersec(rtv1);
	if (ft_strcmp(rtv1->aff_obj.name, "Cylinder") == 0)
		aff_cylinder(rtv1, rtv1->aff_obj);
	else if (ft_strcmp(rtv1->aff_obj.name, "Sphere") == 0)
		aff_sphere(rtv1, rtv1->aff_obj);
	else if (ft_strcmp(rtv1->aff_obj.name, "Plane") == 0)
		aff_plane(rtv1, rtv1->aff_obj);
	else if (ft_strcmp(rtv1->aff_obj.name, "Cone") == 0)
		aff_cone(rtv1, rtv1->aff_obj);
	else 
		return;
}

void        ft_create_rays(t_rt	*rtv1)
{
	rtv1->x = -1;
	rtv1->y = -1;
	while(++rtv1->y < HEIGHT)
	{
		rtv1->x = -1;
		while(++rtv1->x < WIDTH)
		{
			rtv1->rays[rtv1->x + (rtv1->y * HEIGHT)] = (t_3d_ray){(t_vec){rtv1->x - rtv1->mid_x, rtv1->y - rtv1->mid_y, 0}, (t_vec){0, 0, 1}};
			aff_form(rtv1);
		}
	}
	mlx_put_image_to_window(rtv1->mlx->mlx_ptr, rtv1->mlx->win_ptr, rtv1->mlx->win.ptr, 0, 0);
	ft_img_dark(rtv1->mlx->win);
	free(rtv1->obj.cone);
	free(rtv1->obj.cylinder);
	free(rtv1->obj.sphere);
	free(rtv1->obj.plane);
	free(rtv1->aff_obj.cone);
	free(rtv1->aff_obj.cylinder);
	free(rtv1->aff_obj.sphere);
	free(rtv1->aff_obj.plane);
	free(rtv1->aff_obj.t_cone);
	free(rtv1->aff_obj.t_cylinder);
	free(rtv1->aff_obj.t_sphere);
	free(rtv1->aff_obj.t_plane);
	// free(rtv1->int_obj.cone);
	// free(rtv1->int_obj.cylinder);
	// free(rtv1->int_obj.sphere);
	// free(rtv1->int_obj.plane);
	// free(rtv1->int_obj.t_cone);
	// free(rtv1->int_obj.t_cylinder);
	// free(rtv1->int_obj.t_sphere);
	// free(rtv1->int_obj.t_plane);
	free(rtv1->rays);
	free(rtv1->shadow);
}
