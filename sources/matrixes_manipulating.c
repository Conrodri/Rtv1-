/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixes_manipulating.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:19:40 by conrodri          #+#    #+#             */
/*   Updated: 2020/03/09 13:22:10 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


# include "../includes/rtv1.h"

t_vec   ft_multiply_1x3matrixes(t_vec a, float **y)
{
    a.x = a.x * y[0][0] + a.x * y[1][0] + a.x * y[2][0];
    a.y = a.y * y[0][1] + a.y * y[1][1] + a.y * y[2][1];
    a.z = a.z * y[0][2] + a.y * y[1][2] + a.y * y[2][2];
    return(a);
}

float       **ft_multiply_3x3_matrixes(float **x, float **y, t_rt *rtv1)
{
    float **oui;

    oui = ft_new_matrix(rtv1, 3, 3);
    while( rtv1->resi < 3)
    {
        while(rtv1->resj < 3)
        {
            rtv1->xi = rtv1->resi;
            rtv1->yj = rtv1->resj;
            while(rtv1->yi < 3)
                oui[rtv1->resi][rtv1->resj] += x[rtv1->xi][rtv1->xj++]
                    * y[rtv1->yi++][rtv1->yj];
            rtv1-> xi++;
            rtv1->xj = 0;
            rtv1->yi = 0;
            rtv1->yj++;
            rtv1->resj++;
        }
        rtv1->resj = 0;
        rtv1->resi++;
    }
    ft_init_struct_mat(rtv1);
    return (oui);
}

void        print_matrixes(float **matrix)
{
    int m = 0;
    int n = 0;
    while(m < 3)
    {
        while(n < 3)
        {
            printf("%.0f\t", matrix[m][n]);    
            n++;
        }
        printf("\n");
        m++;
        n = 0;
    }
}

void        print_vec(t_vec a)
{
    printf("x = %f, y = %f, z = %f\n", a.x, a.y, a.z);
}

float       **ft_new_matrix (t_rt *rtv1, int y, int x)
{
    rtv1->new_matrix = (float**)malloc(sizeof(float*) * y);
    while(rtv1->resi < y)
    {
        rtv1->new_matrix[rtv1->resi] = (float*)malloc(sizeof(float) * x);
        rtv1->resj = 0;
        while(rtv1->resj < x)
            rtv1->new_matrix[rtv1->resi][rtv1->resj++] = 0;
        rtv1->resi++;
    }
    rtv1->resi = 0;
    rtv1->resj = 0;
    return (rtv1->new_matrix);
}

float       **ft_fill_matrix_3x3(t_vec a, t_vec b, t_vec c, t_rt *rtv1)
{
    float **new;

    new = ft_new_matrix(rtv1, 3, 3);
    new[0][0] = a.x;
    new[0][1] = a.y;
    new[0][2] = a.z;
    new[1][0] = b.x;
    new[1][1] = b.y;
    new[1][2] = b.z;
    new[2][0] = c.x;
    new[2][1] = c.y;
    new[2][2] = c.z;
    return (new);
}

t_vec	ft_deg_to_rad_vec(t_vec nb)
{
	return ((t_vec){nb.x * M_PI / 180, nb.y * M_PI / 180, nb.x * M_PI / 180});
}

float	get_t(float a, float b, float d)
{
	float	t1;
	float	t2;

	t1 = (-b - sqrt(d)) / (2 * a);
	t2 = (-b + sqrt(d)) / (2 * a);
	if ((t1 <= t2 && t1 >= 0) || (t1 >= 0 && t2 < 0))
		return (t1);
	if ((t2 <= t1 && t2 >= 0) || (t2 >= 0 && t1 < 0))
		return (t2);
	return (-1);
}
