/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 22:48:54 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/06 22:50:09 by mponomar         ###   ########.fr       */
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
