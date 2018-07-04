/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <mponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:11:00 by mponomar          #+#    #+#             */
/*   Updated: 2018/02/24 18:11:00 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			calculate(int value, int base , char *str, int *i)
{
	char		*look;
	
	look = "0123456789ABCDEF";
	if (value >= base)
		calculate(value / base, base, str, i);
	str[*i] = look[value % base];
	(*i)++;
}

char			*ft_itoa_hex(int value, int base)
{
	char		*str;
	int			i;
	
	if (base < 2 || base > 16 || !(str = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	ft_bzero(str, 35);
	i = 0;
	if (base == 16)
	{
		str[0] = '0';
		str[1] = 'x';
		i += 2;
	}
	calculate(value, base, str, &i);
	str[i] = '\0';
	return (str);
}