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

#include "fdf.h"

void line(int x0, int y0, int x1, int y1, t_fdf *fdf) 
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
	//ft_printf("x0: %d - y0: %d\n", x0, y0);
	while(1)
	{
    	mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, 0xFFFFFF);
    
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
			line((int)(coor->x * WIDTH/2/fdf->x_lines + MOVE_X), (int)(coor->y * HEIGHT/2/fdf->y_lines + MOVE_Y), (int)(coor->next->x * WIDTH/2/fdf->x_lines + MOVE_X), (int)(coor->next->y * HEIGHT/2/fdf->y_lines + MOVE_Y), fdf);
		else
			i = 0;
		n = fdf->x_lines;
		tmp = coor;
		while (n-- > 0 && tmp)
			tmp = tmp->next;
		if (tmp)
			line((int)(coor->x * WIDTH/2/fdf->x_lines + MOVE_X), (int)(coor->y * HEIGHT/2/fdf->y_lines + MOVE_Y), (int)(tmp->x * WIDTH/2/fdf->x_lines + MOVE_X), (int)(tmp->y * HEIGHT/2/fdf->y_lines + MOVE_Y), fdf);	
		i++;
		coor = coor->next;
	}
}

int exit_button(int key)
{
	key = 0;
	exit(0);
}

void initWindow(t_fdf *fdf, t_coor *coor)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");

	show_map_by_coor(fdf, coor);
	// drawing_net(fdf, coor);
	
	// mlx_hook(fdf->win, 2, 0, key_hook, fdf);

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

	pars_data(argv[1], fdf, coor);
	cast_my_coor_in_2d(fdf, coor);
	initWindow(fdf, coor);


	//check_list(coor);
	return (0);
}