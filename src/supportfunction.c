/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supportfunction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 22:27:48 by mponomar          #+#    #+#             */
/*   Updated: 2018/07/06 22:28:09 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.hfdf."

void	print_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	free_str(char **str, int x)
{
	int	i;

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
