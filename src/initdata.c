/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 22:48:54 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/08 15:47:55 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf		*init_fdf(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->line = NULL;
	fdf->x_lines = 0;
	fdf->y_lines = 0;
	fdf->coor = NULL;
	fdf->x_rad = -0.08;
	fdf->y_rad = 0.05;
	fdf->z_rad = 0.05;
	fdf->size = 2;
	fdf->dx = 0;
	fdf->dy = 0;
	fdf->sx = 0;
	fdf->sy = 0;
	fdf->err = 0;
	fdf->x0 = 0;
	fdf->y0 = 0;
	fdf->x1 = 0;
	fdf->y1 = 0;
	return (fdf);
}

t_coor		*init_coor(void)
{
	t_coor	*coor;

	coor = (t_coor *)malloc(sizeof(t_coor));
	coor->x = 0;
	coor->y = 0;
	coor->z = 0;
	coor->color = WHITE;
	coor->next = NULL;
	return (coor);
}

void		init_window(t_fdf *fdf, t_coor *coor)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	show_map_by_coor(fdf, coor);
	mlx_hook(fdf->win, 2, 0, hook, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, exit_button, 0);
	mlx_loop(fdf->mlx);
}
