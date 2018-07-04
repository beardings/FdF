
#include "fdf.h"

t_fdf *init_fdf(void)
{
	t_fdf *fdf = (t_fdf *)malloc(sizeof(t_fdf));

	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->line = NULL;
	fdf->x_lines = 0;
	fdf->y_lines = 0;

	fdf->x_rad = -0.08;
	fdf->y_rad = 0.05;
	fdf->z_rad = 0.05;

	return (fdf);
}

t_coor *init_coor(void)
{
	t_coor *coor;

	coor = (t_coor *)malloc(sizeof(t_coor));
	coor->x = 0;
	coor->y = 0;
	coor->z = 0;
	coor->color = WHITE;
	coor->next = NULL;

	return (coor);
}
