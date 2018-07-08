/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:08:14 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/08 15:46:33 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		print_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

int			exit_button(int key)
{
	key = 0;
	exit(0);
}

int			main(int argc, char **argv)
{
	t_coor	*coor;
	t_fdf	*fdf;

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
