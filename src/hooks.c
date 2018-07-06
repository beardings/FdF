/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 21:33:43 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/06 22:39:44 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	change_position(int key, t_fdf *fdf)
{
	int		x;
	int		y;
	t_coor	*tmp;

	x = 0;
	y = 0;
	tmp = fdf->coor;
	if (key == 123)
		x = -1;
	else if (key == 124)
		x = 1;
	else if (key == 125)
		y = 1;
	else if (key == 126)
		y = -1;
	while (tmp)
	{
		tmp->x += x;
		tmp->y += y;
		tmp = tmp->next;
	}
}

static void	zoom_window(int key, t_fdf *fdf)
{
	if (key == 69)
		fdf->size *= 0.9;
	else if (key == 78)
		fdf->size *= 1.1;
}

static void	change_z(int key, t_fdf *fdf)
{
	if (key == 12 || key == 13)
	{
		if (key == 12)
			fdf->x_rad += 0.05;
		else
			fdf->x_rad -= 0.05;
	}
	else if (key == 0 || key == 1)
	{
		if (key == 0)
			fdf->y_rad += 0.05;
		else
			fdf->y_rad -= 0.05;
	}
	else if (key == 6 || key == 7)
	{
		if (key == 6)
			fdf->z_rad += 0.05;
		else
			fdf->z_rad -= 0.05;
	}
	cast_my_coor_in_2d(fdf, fdf->coor);
	fdf->x_rad = 0;
	fdf->y_rad = 0;
	fdf->z_rad = 0;
}

static void	change_color(int key, t_fdf *fdf)
{
	int		color;
	t_coor	*tmp;

	color = 0;
	tmp = fdf->coor;
	if (key == 18)
		color = GREEN;
	else if (key == 19)
		color = GREEN_LIGHT;
	else if (key == 20)
		color = RED;
	else if (key == 21)
		color = RED_CRIMSON;
	else if (key == 22)
		color = BLUE;
	else if (key == 23)
		color = BLUE_LIGHT;
	else if (key == 26)
		color = WHITE;
	while (tmp)
	{
		tmp->color = color;
		tmp = tmp->next;
	}
}

int			hook(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	else if (key == 123 || key == 124 ||
		key == 125 || key == 126)
		change_position(key, fdf);
	else if (key == 69 || key == 78)
		zoom_window(key, fdf);
	else if (key == 12 || key == 13 || key == 0 ||
			key == 1 || key == 6 || key == 7)
		change_z(key, fdf);
	else if (key == 18 || key == 19 || key == 20 ||
			key == 21 || key == 22 || key == 23 || key == 26)
		change_color(key, fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	show_map_by_coor(fdf, fdf->coor);
	return (0);
}
