/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:58:46 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/06 21:56:54 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	hex_to_int(char *hex)
{
	int		color;
	int		i;
	char	c;

	color = 0;
	i = 2;
	while (hex[i])
	{
		c = hex[i];
		if (c >= '0' && c <= '9')
			c = c - '0';
		else if (c >= 'a' && c <= 'f')
			c = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			c = c - 'A' + 10;
		color = (color << 4) | (c & 0xF);
		i++;
	}
	return (color);
}

int	set_color(t_point p)
{
	if (p.color_is_set == 1)
		return (p.color);
	else if (p.org_z != 0)
		return (Z_COLOR);
	else
		return (DEFAULT_COLOR);
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

int	get_gradient(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_point b_p, t_point e_p, t_point c_p)
{
	double	percentage;
	int		red;
	int		green;
	int		blue;

	b_p.color = set_color(b_p);
	e_p.color = set_color(e_p);
	if (b_p.color == e_p.color)
		return (b_p.color);
	if (abs(b_p.x - e_p.x) > abs(b_p.y - e_p.y))
		percentage = percent(b_p.x, e_p.x, c_p.x);
	else
		percentage = percent(b_p.y, e_p.y, c_p.y);
	red = get_gradient((b_p.color >> 16) & 0xFF, (e_p.color >> 16) & 0xFF,
			percentage);
	green = get_gradient((b_p.color >> 8) & 0xFF, (e_p.color >> 8) & 0xFF,
			percentage);
	blue = get_gradient(b_p.color & 0xFF, e_p.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
