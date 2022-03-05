/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:58:46 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/05 01:06:15 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	hex_to_int(char *hex)
{
	int	color;
	int	i;
	char	c;
	
	color = 0;
	i = 2;
	while (hex[i])
	{
		c = hex[i];
		if (c >= '0' && c <= '9')
			c = c - '0';
		else if (c >= 'a' && c <='f')
			c = c - 'a' + 10;
		else if (c >= 'A' && c <='F')
			c = c - 'A' + 10;
		color = (color << 4) | (c & 0xF);
		i++;
	}
	return (color);
}

int	get_color(t_point b_p, t_point e_p)
{
	(void) e_p;

	if (b_p.z != 0 && b_p.color_is_set == 0)
		return (Z_COLOR);
	else if (b_p.color_is_set == 1)
		return (b_p.color);
	else
		return (DEFAULT_COLOR);
}