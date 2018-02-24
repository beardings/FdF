/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <mponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:45:00 by mponomar          #+#    #+#             */
/*   Updated: 2018/02/24 15:05:36 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int keyboard_key(int key, void *param)
{
	
	//ft_printf("%d\n", key);
	
	if (key == 53) // action esc
		exit(0);
	return (0);
}

int mouse_key(int key, void *param)
{
	//ft_printf("%d\n", key);
	
	if (key == 4) // action down
	{
	
	}
	else if (key == 5) // action up
	{
	
	}
	return (0);
}

int		main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;

	if (argc != 2)
		return (0);
	
	
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "FdF");
	
	int x = 0;
	int y = 0;
	int rgb = mlx_get_color_value(mlx_ptr, RED_CRIMSON);
	
	while (y < 25)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, rgb);
			x++;
		}
		y++;
	}
	
	mlx_key_hook(win_ptr, keyboard_key, (void *)0);
	mlx_mouse_hook(win_ptr, mouse_key, (void *)0);
	
	
	char *str = ft_itoa_hex(rgb, 16);
	ft_printf("int color rgb -> %d\n", rgb);
	ft_printf("color with hex->> %s", str);
	
	mlx_loop(mlx_ptr);
	
	return (0);
}
