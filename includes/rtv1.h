/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:39:27 by conrodri          #+#    #+#             */
/*   Updated: 2020/03/09 17:07:11 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define BUFF_SIZE 32
# include "../libft/includes/libft.h"
# include "keys.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <fcntl.h>
# define FOV 60
# define WIDTH 640
# define HEIGHT 480

typedef struct		s_vec
{
	float 		x;
	float 		y;
	float 		z;
}					t_vec;

typedef struct		s_light
{	
	t_vec		light_pos;
	float		light_radius;
	t_rgb		light_color;
}					t_light;

typedef struct		s_camera
{
	t_vec		cam_pos;
	t_vec		cam_dir;
	t_vec		cam_right;
	t_vec		cam_down;
}					t_camera;

typedef struct		s_sphere
{
	t_vec		centre;
	float		radius;
	t_rgb		color;
}					t_sphere;

typedef struct		s_plane
{
	t_vec		normal;
	t_vec		angle;
	t_rgb		color;
}					t_plane;

typedef struct		s_cylinder
{
	t_vec		pos;
	t_vec		angle;
	float		radius;
	t_rgb		color;
}					t_cylinder;

typedef struct		s_cone
{
	t_vec		pos;
	t_vec		angle;
	float		radius;
	t_rgb		color;
}					t_cone;

typedef struct		s_3d_ray
{
	t_vec		ray_or;
	t_vec		ray_dir;
}					t_3d_ray;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_img	win;
}				t_mlx;

typedef struct		s_obj
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_cone		*cone;
	float		*t_sphere;
	float		*t_plane;
	float		*t_cone;
	float		*t_cylinder;
	char		*name;
	t_light		light;
}					t_obj;

typedef struct		s_rt
{
	t_mlx		*mlx;
	t_real		vec;
	t_3d_ray	*shadow;
	t_3d_ray	*rays;
	int			keys[MAX];
	t_obj		obj;
	t_obj		aff_obj;
	t_obj		int_obj;
	t_vec		me;
	t_vec		angle;
	float		**matrixes;
	t_vec 		cube_vec[8];
	int 		xi;
	int 		xj;
	int 		yi;
	int 		yj;
	float		t;
	int			x;
	int			y;
	int 		resi;
	int 		resj;
	float		fov_x;
	float		fov_y;
	float		mid_x;
	float		mid_y;
	int			nb_sphere;
	int			nb_cylinder;
	int			nb_plane;
	int			nb_cone;
	int			nb_light;
	int			nb_allobj;
	t_camera	*cam;
	float		**new_matrix;
	float		**rotationX;
	float		**rotationY;
	float		**rotationZ;
	float		**rotationXY;
	float		**rotationXYZ;
	float		intensity;
	float		dt;
	int			i;
	t_vec		pi;
	t_vec		l;
	t_vec		n;
	t_rgb		color;
}					t_rt;


int			main(int ac, char **av);
int			main2(void);
t_vec		ft_create_vec(float x, float y, float z);
t_vec		vec_mul(t_vec a, float **tab);
t_vec		ft_add_vec(t_vec vec, t_vec add);
void        print_vec(t_vec a);
t_vec		ft_deg_to_rad_vec(t_vec nb);
t_vec		vec_turn(t_vec point, t_vec angle);
t_rt   		*ft_init_struct_mat(t_rt *rtv1);
float       **ft_new_matrix(t_rt *rtv1, int y, int x);
float       **ft_fill_matrix_3x3(t_vec a, t_vec b, t_vec c, t_rt *rtv1);
t_vec		ft_multiply_1x3matrixes(t_vec a, float **y);
float       **ft_multiply_3x3_matrixes(float **x, float **y, t_rt *rtv1);
void        print_matrixes(float **matrix);
void        print_ray(t_vec a, int i);
t_vec		ft_sub_vec(t_vec a, t_vec sub);
float		vec_magnitude(t_vec a);
t_vec		vec_normalize(t_vec a);
void		ft_create_camera(t_rt *rtv1);
t_vec		ft_negativ_vec(t_vec a);
t_vec		vec_cross_product(t_vec a, t_vec b);
float		dot_product(t_vec a, t_vec b);
t_vec		vec_mul_vec(t_vec a, t_vec b);
t_vec		total_vec_mult_float(t_vec a, float nb);
void        ft_create_rays(t_rt *rtv1);
void		ft_init_sphere(t_rt *rtv1);
t_vec		ft_sub_vec_pi(t_vec a);

t_vec		get_norm_cone(t_cone cone, t_vec pi);
t_vec		get_norm_sphere(t_sphere sphere, t_vec a);
t_vec		get_norm_cylinder(t_cylinder cyl, t_vec pi);
t_vec		normalize(t_vec norm);

t_rgb		total_rgb_mult_float(t_rgb a, float nb);
t_rgb		add_color(t_rgb color, t_rgb nb);
t_rgb		color_effect(t_rgb col);
t_rgb		div_color(t_rgb color);

t_sphere	ft_copy_sphere(t_sphere new_sphere, t_sphere old_sphere);

t_cone		ft_fill_cone(t_cone cone, t_vec new_centre, t_vec new_angle, float new_radius, t_rgb new_color);
float		int_cyl(t_cylinder cylinder, t_3d_ray *rays);
float		int_plane(t_plane plane, t_3d_ray *rays, float t);
float		int_sph(t_sphere sphere, t_3d_ray *rays, float t);
float		int_cone(t_cone cone, t_3d_ray *rays);

void		aff_form(t_rt *rtv1);
t_obj		which_intersec(t_rt *rtv1);
void		stock_intersec(t_rt *rtv1, t_3d_ray *rays);

void		aff_shadows(t_rt *rtv1, t_vec pi);
void		aff_cylinder(t_rt *rtv1, t_obj obj);
void		aff_sphere(t_rt *rtv1, t_obj obj);
void		aff_plane(t_rt *rtv1, t_obj obj);
void		aff_cone(t_rt *rtv1, t_obj obj);

t_camera	*ft_fill_camera(t_camera *new_camera);
t_cylinder	ft_fill_cylinder(t_cylinder cylinder, t_vec new_centre, t_vec new_angle, float new_radius, t_rgb new_color);
t_plane		ft_fill_plane(t_plane plane, t_vec new_normal, t_vec new_angle, t_rgb new_color);
t_sphere	ft_fill_sphere(t_sphere sphere, t_vec new_centre, float new_radius, t_rgb new_color);
t_light		ft_fill_light(t_light light, t_vec new_pos, float new_radius, t_rgb new_color);

void		ft_aff_sphere(t_sphere *sphere, t_light *light, t_3d_ray rays, int x, int y, t_rt *rtv1, float t);

#endif
