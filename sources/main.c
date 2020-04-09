/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:45:26 by conrodri          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/03/09 18:00:39 by conrodri         ###   ########lyon.fr   */
=======
/*   Updated: 2020/03/06 18:34:45 by Admin            ###   ########.fr       */
>>>>>>> 80c8fa4baa85a92481a273b47071002142370176
/*                                                                            */
/* ************************************************************************** */


# include "../includes/rtv1.h"

t_rt				*ft_init_struct_mat(t_rt *rtv1)
{
    rtv1->xi = 0;
    rtv1->xj = 0;
    rtv1->yi = 0;
    rtv1->yj = 0;
    rtv1->resi = 0;
    rtv1->resj = 0;
	return(rtv1);
}

static void			init_mall(t_rt *rtv1)
{
	if (!(rtv1->shadow = malloc(sizeof(t_3d_ray) * (WIDTH * HEIGHT))))
		ft_error("Shadow Malloc error");
	if (!(rtv1->rays = malloc(sizeof(t_3d_ray) * (WIDTH * HEIGHT))))
		ft_error("rays Malloc error");
	if (!(rtv1->obj.plane = (t_plane*)malloc(sizeof(t_plane) * rtv1->nb_plane)))
		ft_error("plane Malloc error");
	if (!(rtv1->obj.sphere = (t_sphere*)malloc(sizeof(t_sphere) * rtv1->nb_sphere)))
		ft_error("sphere Malloc error");
	if (!(rtv1->obj.cylinder = (t_cylinder*)malloc(sizeof(t_cylinder) * rtv1->nb_cylinder)))
		ft_error("cylinder Malloc error");
	if (!(rtv1->obj.cone = (t_cone*)malloc(sizeof(t_cone) * rtv1->nb_cone)))
		ft_error("cone Malloc error");
	if (!(rtv1->obj.t_plane = (float*)malloc(sizeof(float) * rtv1->nb_plane)))
		ft_error("Tab Malloc error");
	if (!(rtv1->obj.t_cone = (float*)malloc(sizeof(float) * rtv1->nb_cone)))
		ft_error("Tab Malloc error");
	if (!(rtv1->obj.t_sphere = (float*)malloc(sizeof(float) * rtv1->nb_sphere)))
		ft_error("Tab Malloc error");
	if (!(rtv1->obj.t_cylinder = (float*)malloc(sizeof(float) * rtv1->nb_cylinder)))
		ft_error("Tab Malloc error");
	
	if (!(rtv1->aff_obj.plane = (t_plane*)malloc(sizeof(t_plane) * rtv1->nb_plane)))
		ft_error("Tab Malloc error");
	if (!(rtv1->aff_obj.sphere = (t_sphere*)malloc(sizeof(t_sphere) * rtv1->nb_sphere)))
		ft_error("Tab Malloc error");
	if (!(rtv1->aff_obj.cone = (t_cone*)malloc(sizeof(t_cone) * rtv1->nb_cone)))
		ft_error("Tab Malloc error");
	if (!(rtv1->aff_obj.cylinder = (t_cylinder*)malloc(sizeof(t_cylinder) * rtv1->nb_cylinder)))
		ft_error("Tab Malloc error");
	if (!(rtv1->aff_obj.t_plane = (float*)malloc(sizeof(float) * rtv1->nb_plane)))
		ft_error("Tab Malloc error");
	if (!(rtv1->aff_obj.t_cone = (float*)malloc(sizeof(float) * rtv1->nb_cone)))
		ft_error("Tab Malloc error");
	if (!(rtv1->aff_obj.t_sphere = (float*)malloc(sizeof(float) * rtv1->nb_sphere)))
		ft_error("Tab Malloc error");
	if (!(rtv1->aff_obj.t_cylinder = (float*)malloc(sizeof(float) * rtv1->nb_cylinder)))
		ft_error("Tab Malloc error");

	// if (!(rtv1->int_obj.plane = (t_plane*)malloc(sizeof(t_plane) * rtv1->nb_plane)))
	// 	ft_error("rtv1->int_obj Malloc error");
	// if (!(rtv1->int_obj.sphere = (t_sphere*)malloc(sizeof(t_sphere) * rtv1->nb_sphere)))
	// 	ft_error("rtv1->int_obj Malloc error");
	// if (!(rtv1->int_obj.cone = (t_cone*)malloc(sizeof(t_cone) * rtv1->nb_cone)))
	// 	ft_error("rtv1->int_obj Malloc error");
	// if (!(rtv1->int_obj.cylinder = (t_cylinder*)malloc(sizeof(t_cylinder) * rtv1->nb_cylinder)))
	// 	ft_error("rtv1->int_obj Malloc error");
	// if (!(rtv1->int_obj.t_plane = (float*)malloc(sizeof(float) * rtv1->nb_plane)))
	// 	ft_error("rtv1->int_obj Malloc error");
	// if (!(rtv1->int_obj.t_cone = (float*)malloc(sizeof(float) * rtv1->nb_cone)))
	// 	ft_error("rtv1->int_obj Malloc error");
	// if (!(rtv1->int_obj.t_sphere = (float*)malloc(sizeof(float) * rtv1->nb_sphere)))
	// 	ft_error("rtv1->int_obj Malloc error");
	// if (!(rtv1->int_obj.t_cylinder = (float*)malloc(sizeof(float) * rtv1->nb_cylinder)))
	// 	ft_error("rtv1->int_obj Malloc error");
	
	rtv1->obj.sphere[0] = ft_fill_sphere(rtv1->obj.sphere[0], (t_vec){180, -130, 30}, 150, BLUE);
<<<<<<< HEAD
	rtv1->obj.sphere[1] = ft_fill_sphere(rtv1->obj.sphere[1], (t_vec){-180, -130, 30}, 150, BLUE);
	rtv1->obj.plane[0] = ft_fill_plane(rtv1->obj.plane[0], (t_vec){0, 0, 100}, (t_vec){0, 1, 0}, RED);
	rtv1->obj.plane[1] = ft_fill_plane(rtv1->obj.plane[1], (t_vec){0, 0, 0}, (t_vec){1, 0, 0}, PURPLE);
	rtv1->obj.cylinder[0] = ft_fill_cylinder(rtv1->obj.cylinder[0], (t_vec){0, 200, 0}, (t_vec){1, 0, 0}, 20, GREEN);
	rtv1->obj.cylinder[1] = ft_fill_cylinder(rtv1->obj.cylinder[1], (t_vec){ -250, -200, 0}, (t_vec){0, 1, 0}, 20, YELLOW);
	rtv1->obj.cone[0] = ft_fill_cone(rtv1->obj.cone[0], (t_vec){0, 100, 75}, (t_vec){0, 0.07, 0}, 20, ORANGE);
	rtv1->obj.light = ft_fill_light(rtv1->obj.light, (t_vec){-100, 800, -250}, 1, WHITE);
=======
	rtv1->obj.sphere[1] = ft_fill_sphere(rtv1->obj.sphere[1], (t_vec){-180, -130, -100}, 150, BLUE);
	rtv1->obj.plane[0] = ft_fill_plane(rtv1->obj.plane[0], (t_vec){0, -55, 150}, (t_vec){0, 90, 0}, RED);
	rtv1->obj.plane[1] = ft_fill_plane(rtv1->obj.plane[1], (t_vec){0, -55, 150}, (t_vec){90, 0, 0}, PURPLE);
	rtv1->obj.cylinder[0] = ft_fill_cylinder(rtv1->obj.cylinder[0], (t_vec){0, 200, -110}, (t_vec){1, 0, 0}, 20, GREEN);
	rtv1->obj.cylinder[1] = ft_fill_cylinder(rtv1->obj.cylinder[1], (t_vec){ -250, -200, -100}, (t_vec){0, 1, 0}, 20, YELLOW);
	rtv1->obj.cone[0] = ft_fill_cone(rtv1->obj.cone[0], (t_vec){0, 100, -70}, (t_vec){0, 0.07, 0}, 20, ORANGE);
	rtv1->obj.light = ft_fill_light(rtv1->obj.light, (t_vec){-100, 300, -250}, 1, WHITE);
>>>>>>> 80c8fa4baa85a92481a273b47071002142370176
}

static void			init(t_rt *rtv1)
{
	if (!(rtv1->mlx = malloc(sizeof(t_mlx))))
		ft_error("rtv1->mlx Malloc error");
	rtv1->nb_sphere = 2;
	rtv1->nb_plane = 2;
	rtv1->nb_cylinder = 2;
	rtv1->nb_cone = 1;
	rtv1->intensity = 1;
<<<<<<< HEAD
	rtv1->x = -1;
	rtv1->y = -1;
=======
>>>>>>> 80c8fa4baa85a92481a273b47071002142370176
	rtv1->nb_allobj = rtv1->nb_sphere + rtv1->nb_cylinder + rtv1->nb_cone + rtv1->nb_plane;
	rtv1->fov_x = FOV / WIDTH;
	rtv1->fov_y =  36 / HEIGHT;
	rtv1->mid_x = WIDTH * 0.5;
	rtv1->mid_y = HEIGHT * 0.5;
	rtv1->mlx->mlx_ptr = mlx_init();
	rtv1->mlx->win_ptr = mlx_new_window(rtv1->mlx->mlx_ptr, WIDTH, HEIGHT, "rtv1");
}

static int			key_release(int key, t_rt *rtv1)
{
	if (key >= MAX)
		return (0);
	rtv1->keys[key] = 0;
	return (0);
}

int					ft_deal_key(int key, t_rt *rtv1)
{
	// t_cplx		move;

	// move = (t_cplx){0, 0};
	// if (key >= MAX)
	// 	return (0);
	if (key == ESC)
		exit(0);
	// rtv1->keys[key] = 1;
	// if (key == DOWN || key == S)
	// 	rtv1->angle.x -= 3;
	// else if (key == UP || key == W)
	// 	rtv1->angle.x += 3;
	// else if (key == LEFT || key == A)
	// 	rtv1->angle.y += 3;
	// else if (key == RIGHT || key == D)
	// 	rtv1->angle.y -= 3;
	// else if (key == LESS)
	// 	rtv1->angle.z -= 3;
	// else if (key == MORE)
	// 	rtv1->angle.z += 3;
	init_mall(rtv1);
	ft_create_rays(rtv1);
	return (0);
}

t_rt				*ft_init_mat(t_rt *rtv1)
{
	rtv1->rotationX = ft_fill_matrix_3x3((t_vec){1, 0, 0}, (t_vec){0, cos(rtv1->angle.x), -sin(rtv1->angle.x)}, (t_vec){0, sin(rtv1->angle.x) , cos(rtv1->angle.x)}, rtv1);
	rtv1->rotationY = ft_fill_matrix_3x3((t_vec){cos(rtv1->angle.y), 0, sin(rtv1->angle.y)}, (t_vec){0, 1, 0}, (t_vec){-sin(rtv1->angle.y), 0, cos(rtv1->angle.y)}, rtv1);
	rtv1->rotationZ = ft_fill_matrix_3x3((t_vec){cos(rtv1->angle.z), -sin(rtv1->angle.z), 0}, (t_vec){sin(rtv1->angle.z), cos(rtv1->angle.z) , 0}, (t_vec){0, 0, 1}, rtv1);
	rtv1->rotationXY = ft_multiply_3x3_matrixes(rtv1->rotationX, rtv1->rotationY, rtv1);
	rtv1->rotationXYZ = ft_multiply_3x3_matrixes(rtv1->rotationXY, rtv1->rotationZ, rtv1);
	return(rtv1);
}

int					main(int ac , char **av)
{
	t_rt		*rtv1;
	int i;

	i = 0;
	if (ac != 2)
		ft_error("Wrong numbers of arguments");
	(void)ac;
	(void)av;
	if (!(rtv1 = malloc(sizeof(t_rt))))
		ft_error("Rtv1 Malloc error");
	init(rtv1);
	init_mall(rtv1);
	rtv1 = ft_init_struct_mat(rtv1);
	rtv1 = ft_init_mat(rtv1);
	ft_create_img(rtv1->mlx->mlx_ptr, &rtv1->mlx->win, WIDTH, HEIGHT);
	while (++i < MAX)
		rtv1->keys[i] = 0;
	rtv1->me = (t_vec){0, 0, 1};
	rtv1->angle = (t_vec){0, 0, 0};
	ft_create_rays(rtv1);
	mlx_hook(rtv1->mlx->win_ptr, 3, 0, &key_release, rtv1);
	mlx_hook(rtv1->mlx->win_ptr, 2, 0, &ft_deal_key, rtv1);
	mlx_loop(rtv1->mlx->mlx_ptr);
	return(0);
}