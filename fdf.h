/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:08:03 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/01 19:08:05 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/header/libft.h"
# include "libft/header/ft_printf.h"
# include "libft/header/get_next_line.h"
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

# define MOVE_X 400
# define MOVE_Y 300

typedef struct 	s_coor
{
	float 			x;
	float 			y;
	float 			z;
	int				color;
	struct s_coor 	*next;
}				t_coor;


typedef struct 	s_fdf
{
	void *mlx;
	void *win;
	char *line;
	int x_lines;
	int y_lines;

	float	x_rad;
	float	y_rad;
	float	z_rad;

}				t_fdf;

t_coor 	*init_coor(void);
t_fdf 	*init_fdf(void);
void 	free_str(char **str, int x);
void 	print_error(char *str);
void 	pars_data(char *link, t_fdf *fdf, t_coor *coor);
char	*ft_itoa_hex(int value, int base);
void 	cast_my_coor_in_2d(t_fdf *fdf, t_coor *coor);

void	check_list(t_coor *coor);

#endif