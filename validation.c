

#include "fdf.h"

/**********DELETE LATER********************/

#include <stdio.h>

void	check_list(t_coor *coor)
{
	int i;

	i = 0;
	while (coor)
	{
		printf("%d - |x: %f | y: %f | z: %f |\n", i,  coor->x, coor->y, coor->z);
		i++;
		coor = coor->next;
	}
}

/******************************************/

t_coor *create_new_coor(t_coor *coor)
{
	while (coor->next != NULL)
		coor = coor->next;

	coor->next = init_coor();
	return (coor->next);
}

void checkColor(t_coor  *coor, char *str)
{

}

void check_string(t_coor *coor, char *str)
{
	int i;
	int	pl;
	int	min;

	i = 0;
	pl = 0;
	min = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' &&
			str[i] != '+' && str[i] != ',')
			print_error("error1");
		else if (str[i] == '-')
			min++;
		else if (str[i] == '+')
			pl++;
		else if (str[i] == ',')
		{
			checkColor(coor, &str[i + 1]);
			return ;
		}
		i++;

		if (min > 1 || pl > 1 || (min && pl))
			print_error("Unvalid sign in coordinate. 😞");
	}
}

int count_x_lines(t_fdf *fdf, t_coor *coor, int y)
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


void pars_data(char *link, t_fdf *fdf, t_coor *coor)
{
	int fd;
	int y;
	int	count_x;

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
		count_x_lines(fdf, coor, y) != count_x ? print_error("error3") : 0;
		y++;
		free(fdf->line);
	}

	fdf->x_lines = count_x;
	fdf->y_lines = y;

	//check_list(coor);
}