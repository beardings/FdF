/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 15:38:07 by mponomar          #+#    #+#             */
/*   Updated: 2018/02/24 15:01:54 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/header/libft.h"
# include "../libft/header/ft_printf.h"
# include "../libft/header/get_next_line.h"
# include <math.h>
# include <mlx.h>

# define GREEn 0x008000
# define GREEN_LIGHT 0x00FF00

# define RED 0xFF0000
# define RED_CRIMSON 0xDC143C

# define BLUE 0x4169E0
# define BLUE_LIGHT 0x00BFFF

# define WHITE 0xFFFFFF

# define WIDTH 1600
# define HEIGHT 1200

typedef struct s_point
{
	float x;
	float y;
	float z;
	int r;
	int g;
	int b;
	int alpha;
	
} t_point;

typedef struct s_line
{
	t_point *line;
	int len;
	
} t_line;

typedef struct s_map
{
	t_line **map;
	int len;

}; t_map;

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
	int zoom;
	
} t_mlx;

char			*ft_itoa_hex(int value, int base);

#endif
