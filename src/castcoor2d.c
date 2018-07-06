/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castcoor2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 22:45:08 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/06 22:48:11 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		cast_x(t_fdf *fdf, t_coor *coor, float old_y, float old_z)
{
	float	y;
	float	z;

	y = old_y;
	z = old_z;
	coor->y = (y * cos(fdf->x_rad)) + (z * sin(fdf->x_rad));
	coor->z = (-y * sin(fdf->x_rad)) + (z * cos(fdf->x_rad));
}

void		cast_y(t_fdf *fdf, t_coor *coor, float old_x)
{
	float	x;

	x = old_x;
	coor->x = (x * cos(fdf->y_rad)) + (coor->z * sin(fdf->y_rad));
	coor->z = (-x * sin(fdf->y_rad)) + (coor->z * cos(fdf->y_rad));
}

void		cast_z(t_fdf *fdf, t_coor *coor)
{
	float	x;

	x = coor->x;
	coor->x = (x * cos(fdf->z_rad)) - (coor->y * sin(fdf->z_rad));
	coor->y = (x * sin(fdf->z_rad)) + (coor->y * cos(fdf->z_rad));
}

void		cast_my_coor_in_2d(t_fdf *fdf, t_coor *coor)
{
	float	old_y;
	float	old_z;
	float	old_x;

	while (coor)
	{
		old_z = coor->z;
		old_y = coor->y;
		old_x = coor->x;
		cast_x(fdf, coor, old_y, old_z);
		cast_y(fdf, coor, old_x);
		cast_z(fdf, coor);
		coor = coor->next;
	}
}
