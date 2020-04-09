/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:39:47 by conrodri          #+#    #+#             */
/*   Updated: 2020/03/09 16:28:24 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


# include "../includes/rtv1.h"

t_rgb	div_color(t_rgb color)
{
	color.r /= 2;
	color.g /= 2;
	color.b /= 2;
	return(color);
}

t_rgb	color_effect(t_rgb col)
{	
	col.r = (col.r > 255) ? 255 : col.r;
	col.r = (col.r < 0) ? 0 : col.r;
	col.g = (col.g > 255) ? 255 : col.g;
	col.g = (col.g < 0) ? 0 : col.g;
	col.b = (col.b > 255) ? 255 : col.b;
	col.b = (col.b < 0) ? 0 : col.b;
	return (col);
}

t_rgb	mult_color(t_rgb color, int nb)
{
	color.r *= nb;
	color.g *= nb;
	color.b *= nb;
	return (color);
}

t_rgb	add_color(t_rgb color, t_rgb nb)
{
	color.r += nb.r;
	color.g += nb.g;
	color.b += nb.b;
	return (color);
}

t_vec		total_vec_mult_float(t_vec a, float nb)
{
	a.x *= nb;
	a.y *= nb;
	a.z *= nb;
	return (a);
}

t_rgb		total_rgb_mult_float(t_rgb a, float nb)
{
	a.r *= nb;
	a.g *= nb;
	a.b *= nb;
	return (a);
}

t_vec		total_vec_mult_int(t_vec a, int nb)
{
	a.x *= nb;
	a.y *= nb;
	a.z *= nb;
	return (a);
}

t_vec		ft_create_vec(float x, float y, float z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec		ft_sub_vec(t_vec a, t_vec sub)
{
	a.x -= sub.x;
	a.y -= sub.y;
	a.z -= sub.z;
	return (a);
}

t_vec		ft_sub_vec_pi(t_vec a)
{
	a.x -= M_PI;
	a.y -= M_PI;
	a.z -= M_PI;
	return (a);
}

t_vec		ft_add_vec(t_vec a, t_vec add)
{
	a.x += add.x;
	a.y += add.y;
	a.z += add.z;
	return (a);
}

t_vec		ft_div_vec(t_vec a, float add)
{
	a.x /= add;
	a.y /= add;
	a.z /= add;
	return (a);
}

t_vec		vec_mul(t_vec a, float **tab)
{
	a.x = a.x * tab[0][0] + a.y * tab[0][1] + a.z * tab[0][2];
	a.y = a.x * tab[1][0] + a.y * tab[1][1] + a.z * tab[1][2];
	a.z = a.x * tab[2][0] + a.y * tab[2][1] + a.z * tab[2][2];
	return (a);
}

t_camera	*ft_fill_camera(t_camera *new_camera)
{
	t_camera	*camera;

	if (!(camera = malloc(sizeof(t_sphere))))
		ft_error("camera Malloc error");
	camera->cam_pos = new_camera->cam_pos;
	camera->cam_dir = new_camera->cam_dir;
	camera->cam_right = new_camera->cam_right;
	camera->cam_down = new_camera->cam_down;
	return (camera);
}

t_light		ft_fill_light(t_light light, t_vec new_pos, float new_radius, t_rgb new_color)
{
	light.light_pos = new_pos;
	light.light_radius = new_radius;
	light.light_color = new_color;
	return (light);
}

t_light		*ft_create_light(t_vec new_light, t_rgb new_color)
{
	t_light *light;

	if (!(light = malloc(sizeof(t_light))))
		ft_error("light Malloc error");
	light->light_pos = new_light;
	light->light_color = new_color;
	return (light);
}

t_sphere		ft_copy_sphere(t_sphere new_sphere, t_sphere old_sphere)
{
	new_sphere.centre = old_sphere.centre;
	new_sphere.radius = old_sphere.radius;
	new_sphere.color = old_sphere.color;
	return (new_sphere);
}

t_sphere		ft_fill_sphere(t_sphere sphere, t_vec new_centre, float new_radius, t_rgb new_color)
{
	sphere.centre = new_centre;
	sphere.radius = new_radius;
	sphere.color = new_color;
	return (sphere);
}

t_cylinder		ft_fill_cylinder(t_cylinder cylinder, t_vec new_centre, t_vec new_angle, float new_radius, t_rgb new_color)
{
	cylinder.pos = new_centre;
	cylinder.radius = new_radius;
	cylinder.angle = new_angle;
	cylinder.color = new_color;
	return (cylinder);
}

t_cone		ft_fill_cone(t_cone cone, t_vec new_centre, t_vec new_angle, float new_radius, t_rgb new_color)
{
	cone.pos = new_centre;
	cone.radius = new_radius;
	cone.angle = new_angle;
	cone.color = new_color;
	return (cone);
}

t_sphere		*ft_create_sphere(t_sphere *new_sphere)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		ft_error("sphere Malloc error");
	sphere->centre = new_sphere->centre;
	sphere->radius = new_sphere->radius;
	sphere->color = new_sphere->color;
	return (sphere);
}

t_plane		ft_fill_plane(t_plane plane, t_vec new_normal, t_vec new_angle, t_rgb new_color)
{
	plane.normal = new_normal;
	plane.angle = new_angle;
	plane.color = new_color;
	return (plane);
}

t_plane		*ft_create_plan(t_plane *new_plan)
{
	t_plane	*plane;

	if (!(plane = malloc(sizeof(t_plane))))
		ft_error("plan Malloc error");
	plane->normal = new_plan->normal;
	plane->angle = new_plan->angle;
	plane->color = new_plan->color;
	return (plane);
}

t_rgb	get_light_color(t_light *light)
{
	return (light->light_color);
}

t_vec	get_light_position(t_light *light)
{
	return (light->light_pos);
}

t_vec	get_norm_plan(t_plane *plan)
{
	return (plan->normal);
}

t_rgb	get_color_plan(t_plane *plan)
{
	return (plan->color);
}

float	dot_product(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	get_norm_sphere(t_sphere sphere, t_vec a)
{
	return (ft_div_vec(ft_sub_vec(a, sphere.centre), sphere.radius));
}

t_vec	normalize(t_vec norm)
{
	float mg;

	mg = sqrtf(norm.x * norm.x + norm.y * norm.y + norm.z * norm.z);
	norm = ft_div_vec(norm,mg);
	return (norm);
}

t_vec	get_norm_cylinder(t_cylinder cyl, t_vec pi)
{
	t_vec	normal;
	double	dis;

	normal = ft_sub_vec(pi, cyl.pos);
	dis = dot_product(normal, cyl.angle);
	normal.x = cyl.pos.x + cyl.angle.x * dis;
	normal.y = cyl.pos.y + cyl.angle.y * dis;
	normal.z = cyl.pos.z + cyl.angle.z * dis;
	normal = ft_sub_vec(pi, normal);
	normalize(normal);
	return (normal);
}

t_vec	get_norm_cone(t_cone cone, t_vec pi)
{
	double	side_len;
	t_vec	normal;

	normal = ft_sub_vec(pi, cone.pos);
	side_len = sqrt(dot_product(normal, normal));
	side_len /= cos(cone.radius);
	if (dot_product(normal, cone.angle) < 0)
		side_len = -side_len;
	normal.x = cone.pos.x + side_len * cone.angle.x;
	normal.y = cone.pos.y + side_len * cone.angle.y;
	normal.z = cone.pos.z + side_len * cone.angle.z;
	normal = ft_sub_vec(pi, normal);
	normalize(normal);
	return (normal);
}

t_vec	vec_mul_vec(t_vec a, t_vec b)
{
	a.x = a.x * b.x;
	a.y = a.y * b.y;
	a.z = a.z * b.z;
	return (a);
}