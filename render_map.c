/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:27:19 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/02 01:47:28 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_point	get_point(t_data *data, int x, int y, char *s)
{
	t_point p;
	char	**str = NULL;

	p.x = x;
	p.y = y;
	p.color_is_set = 0;
	if (ft_strchr(s, ','))
	{
		str = ft_split(s, ',');
		p.z = ft_atoi(str[0]);
		p.color = str[1];
		p.color_is_set = 1;
	}
	else
		p.z = ft_atoi(s);
	p.x *= data->zoom;
	p.y *= data->zoom;
	p.z *= data->zoom;
	isometric_proj(&p, data);
	p.x += WIDTH / 3;
	p.y += HEIGHT / 3;
	return (p);
}

void	draw_h(t_data *data, int x, int y)
{
	t_point p1;
	t_point p2;

	p1 = get_point(data, x, y, data->z_matrix[y][x]);
	p2 = get_point(data, x + 1, y, data->z_matrix[y][x + 1]);
	draw_line_bresenham(data, p1 , p2);
}

void	draw_v(t_data *data, int x, int y)
{
	t_point p1;
	t_point p2;

	p1 = get_point(data, x, y, data->z_matrix[y][x]);
	p2 = get_point(data, x, y + 1, data->z_matrix[y + 1][x]);
	draw_line_bresenham(data, p1 , p2);
}

void	render_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.heigth)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (x < data->map.width - 1)
				draw_h(data, x, y);
			if (y < data->map.heigth - 1)
				draw_v(data, x, y);
			x++;
		}
		y++;
	}
}