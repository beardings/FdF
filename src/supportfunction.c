/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supportfunction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 22:27:48 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/08 17:09:41 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		free_str(char **str, int x)
{
	int		i;

	i = 0;
	if (str)
	{
		while (i < x)
		{
			free(str[i]);
			str[i] = NULL;
			i++;
		}
	}
}

void		set_next_coor(t_coor *coor, t_fdf *fdf, t_coor *tmp)
{
	fdf->x0 = (int)(coor->x * W + 300);
	fdf->x1 = (int)(tmp->x * W + 300);
	fdf->y0 = (int)(coor->y * H + 400);
	fdf->y1 = (int)(tmp->y * H + 400);
}

void		set_new_coor(t_coor *coor, t_fdf *fdf)
{
	fdf->x0 = (int)(coor->x * W + 300);
	fdf->x1 = (int)(coor->next->x * W + 300);
	fdf->y0 = (int)(coor->y * H + 400);
	fdf->y1 = (int)(coor->next->y * H + 400);
}

void		line(t_fdf *fdf, t_coor *coor)
{
	fdf->dx = abs(fdf->x1 - fdf->x0);
	fdf->dy = abs(fdf->y1 - fdf->y0);
	fdf->sx = fdf->x0 < fdf->x1 ? 1 : -1;
	fdf->sy = fdf->y0 < fdf->y1 ? 1 : -1;
	fdf->err = (fdf->dx > fdf->dy ? fdf->dx : -fdf->dy) / 2;
	while (1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x0, fdf->y0, coor->color);
		if (fdf->x0 == fdf->x1 && fdf->y0 == fdf->y1)
			break ;
		fdf->e2 = fdf->err;
		if (fdf->e2 > -fdf->dx)
		{
			fdf->err -= fdf->dy;
			fdf->x0 += fdf->sx;
		}
		if (fdf->e2 < fdf->dy)
		{
			fdf->err += fdf->dx;
			fdf->y0 += fdf->sy;
		}
	}
}

void		show_map_by_coor(t_fdf *fdf, t_coor *coor)
{
	int		i;
	int		n;
	t_coor	*tmp;

	i = 0;
	while (coor->next && ++i)
	{
		if (i < fdf->x_lines)
		{
			set_new_coor(coor, fdf);
			line(fdf, coor);
		}
		else
			i = 0;
		n = fdf->x_lines;
		tmp = coor;
		while (n-- > 0 && tmp)
			tmp = tmp->next;
		if (tmp)
		{
			set_next_coor(coor, fdf, tmp);
			line(fdf, coor);
		}
		coor = coor->next;
	}
}
