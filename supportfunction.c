

#include "fdf.h"


void print_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void free_str(char **str, int x)
{
	int i;

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