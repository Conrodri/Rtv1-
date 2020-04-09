/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:18:59 by conrodri          #+#    #+#             */
/*   Updated: 2020/03/09 15:11:53 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rtv1.h"

float		int_plane(t_plane plane, t_3d_ray *rays, float t)
{
	float 	a;
	float 	b;

	a = dot_product(ft_sub_vec(rays->ray_or, plane.normal), plane.angle);
	b = dot_product(rays->ray_dir, plane.angle);
	if (b == 0 || (a < 0 && b < 0 ) || (a > 0 && b > 0))
		return (-1);
	t = -a / b;
	return(t > 0 ? t : -1);
}

float		int_sph(t_sphere sphere, t_3d_ray *rays, float t)
{
	t_vec	origin;
	t_vec	direction;
	t_vec	origin_direction;
	float	b;
	float	c;
	float	disc;
	float	t0;
	float	t1;
	float	test;

	origin = rays->ray_or;
	direction = rays->ray_dir;
	test = dot_product(rays->ray_dir, rays->ray_dir);
	origin_direction = ft_sub_vec(origin, sphere.centre);
	b = 2 * dot_product(origin_direction, direction);
	c = dot_product(origin_direction, origin_direction) -\
			(sphere.radius * sphere.radius);
	disc = (b * b) - (4 * test * c);
	if (disc < 0)
		return (0);
	else
	{
		disc = sqrtf(disc);
		t0 = (-b) - disc / (2 * test);
		t1 = (-b) + disc / (2 * test);
		if (t0 < t1)
			t = t0;
		else
			t = t1;
		return (t);
	}
}

float		int_cyl(t_cylinder cylinder, t_3d_ray *rays)
{
	t_vec 	x;
	float 	a;
	float 	b;
	float 	c;
	float 	disc;
	float 	t0;
	float 	t1;
	float 	t;

	x = ft_sub_vec(rays->ray_or, cylinder.pos);
	a = dot_product(rays->ray_dir, cylinder.angle);
	a = dot_product(rays->ray_dir, rays->ray_dir) - a * a;
	b = 2 * (dot_product(rays->ray_dir, x) -\
			dot_product(rays->ray_dir, cylinder.angle) *\
			dot_product(x, cylinder.angle));
	c = dot_product(x, cylinder.angle);
	c = dot_product(x, x) - c * c - (cylinder.radius * cylinder.radius);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (0);
	else
	{
		disc = sqrtf(disc);
		t0 = (-b) - disc;
		t1 = (-b) + disc;
		if (t0 < t1)
			t = t0;
		else
			t = t1;
		return (t);
	}
}

float		int_cone(t_cone cone, t_3d_ray *rays)
{
	t_vec	x;
	float	a;
	float	b;
	float	c;
	float	disc;
	float 	t0;
	float 	t1;
	float 	t;

	x = ft_sub_vec(rays->ray_or, cone.pos);
	a = dot_product(rays->ray_dir, cone.angle);
	a = dot_product(rays->ray_dir, rays->ray_dir) -\
			(1 + cone.radius * cone.radius) * a * a;
	b = 2 * (dot_product(rays->ray_dir, x) - (1 + cone.radius * cone.radius) *\
			dot_product(rays->ray_dir, cone.angle) * dot_product(x, cone.angle));
	c = dot_product(x, cone.angle);
	c = dot_product(x, x) - (1 + cone.radius * cone.radius) * c * c;
	disc = b * b - 4 * a * c; 
	if (disc < 0)
		return (0);
	else
	{
		disc = sqrtf(disc);
		t0 = (-b) - disc;
		t1 = (-b) + disc;
		if (t0 < t1)
			t = t0;
		else
			t = t1;
		return (t);
	}
}
