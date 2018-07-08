/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 22:23:01 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/08 17:36:26 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_coor		*create_new_coor(t_coor *coor)
{
	while (coor->next != NULL)
		coor = coor->next;
	coor->next = init_coor();
	return (coor->next);
}

void		check_color(t_coor *coor, char *str)
{
	int i;

	i = 2;
	if (str[0] != '0')
		print_error("Invalid color. 😞");
	if (str[1] != 'x')
		print_error("Invalid color. 😞");
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			i++;
		else if ((str[i] >= 'A' && str[i] <= 'F')
			|| (str[i] >= 'a' && str[i] <= 'f'))
			i++;
		else
			print_error("Invalid color. 😞");
	}
	if (i > 8)
		print_error("Invalid color. 😞");
	coor->color = ft_atoi_base_16(&str[2]);
}

void		check_string(t_coor *coor, char *str)
{
	int		i;
	int		pl;
	int		min;

	i = 0;
	pl = 0;
	min = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' &&
			str[i] != '+' && str[i] != ',')
			print_error("Invalid coordinate. 😞");
		else if (str[i] == '-')
			min++;
		else if (str[i] == '+')
			pl++;
		else if (str[i] == ',')
		{
			check_color(coor, &str[i + 1]);
			return ;
		}
		i++;
		if (min > 1 || pl > 1 || (min && pl))
			print_error("Invalid sign in coordinate. 😞");
	}
}

int			count_x_lines(t_fdf *fdf, t_coor *coor, int y)
{
	int		x;
	char	**str;

	x = 0;
	str = ft_strsplit(fdf->line, ' ');
	if (coor->next || y > 0)
		coor = create_new_coor(coor);
	while (str[x] != 0)
	{
		check_string(coor, str[x]);
		coor->x = (float)x;
		coor->y = (float)y;
		coor->z = (float)ft_atoi(str[x]);
		x++;
		str[x] ? coor = create_new_coor(coor) : 0;
	}
	free_str(str, x);
	free(str);
	return (x);
}

void		pars_data(char *link, t_fdf *fdf, t_coor *coor)
{
	int		fd;
	int		y;
	int		count_x;

	if ((fd = open(link, O_RDONLY)) < 1 || read(fd, &fdf->line, 0) < 0)
		print_error("Cannot open file. 😞");
	count_x = 0;
	y = 0;
	get_next_line(fd, &fdf->line);
	count_x = count_x_lines(fdf, coor, y);
	y++;
	free(fdf->line);
	while (get_next_line(fd, &fdf->line) > 0)
	{
		if (count_x_lines(fdf, coor, y) != count_x)
			print_error("Invalid map. 😞");
		y++;
		free(fdf->line);
	}
	fdf->x_lines = count_x;
	fdf->y_lines = y;
}
