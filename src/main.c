/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:08:14 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/01 19:08:16 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void line(int x0, int y0, int x1, int y1, t_fdf *fdf, t_coor *coor) 
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = x0 < x1 ? 1 : -1;
	sy = y0 < y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while(1)
	{
    	mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, coor->color);
    
    	if (x0 == x1 && y0 == y1)
    		break;

	    e2 = err;
	    
	    if (e2 >-dx)
	    {
	    	err -= dy;
	    	x0 += sx; 
	    }
	    
	    if (e2 < dy)
	   	{
	   		err += dx; 
	    	y0 += sy; 
	    }
	}
}

void show_map_by_coor(t_fdf *fdf, t_coor *coor)
{
	int i;
	int	n;
	t_coor *tmp;

	i = 1;
	while (coor->next)
	{
		if (i < fdf->x_lines)
			line((int)(coor->x * W + 300), (int)(coor->y * H + 400),
				(int)(coor->next->x * W + 300), (int)(coor->next->y * H + 400), fdf, coor);
		else
			i = 0;
		n = fdf->x_lines;
		tmp = coor;
		while (n-- > 0 && tmp)
			tmp = tmp->next;
		if (tmp)
			line((int)(coor->x * W + 300), (int)(coor->y * H + 400),
				(int)(tmp->x * W + 300), (int)(tmp->y * H + 400), fdf, coor);	
		i++;
		coor = coor->next;
	}
}

int exit_button(int key)
{
	key = 0;
	exit(0);
}


void init_window(t_fdf *fdf, t_coor *coor)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	show_map_by_coor(fdf, coor);
	mlx_hook(fdf->win, 2, 0, hook, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, exit_button, 0);
	mlx_loop(fdf->mlx);
}


int main (int argc, char **argv)
{
	t_coor *coor;
	t_fdf *fdf;

	if (argc != 2)
		print_error("Too many arguments. 😞");

	fdf = init_fdf();
	coor = init_coor();
	fdf->coor = coor;

	pars_data(argv[1], fdf, coor);
	cast_my_coor_in_2d(fdf, coor);
	init_window(fdf, coor);

	return (0);
}