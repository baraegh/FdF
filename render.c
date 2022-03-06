/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:27:25 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/06 03:39:30 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	isometric_proj(t_point	*p)
{
	p->x = (p->x - p->y) * cos(0.8);
	p->y = (p->x + p->y) * sin(0.8) - p->z;
}

void	project(t_point *p, t_data *data)
{
	p->x *= data->view.zoom;
	p->y *= data->view.zoom;
	p->z *= data->view.zoom;
	p->x -= (data->map.width * data->view.zoom) / 2;
	p->y -= (data->map.heigth * data->view.zoom) / 2;
	rotate_x(&p->y, &p->z, data->view.x_teta);
	rotate_y(&p->x, &p->z, data->view.y_teta);
	rotate_z(&p->x, &p->y, data->view.z_teta);
	if (data->view.proj == ISO)
		isometric_proj(p);
	p->x += WIDTH / 2 + data->view.x_offset;
	p->y += (HEIGHT + data->map.heigth * data->view.zoom) / 2
			+ data->view.y_offset;
}

int	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			img_pix_put(&data->img, (t_point){j++, i, 0, 0, 0, 0}, color);
		i++;
	}
	return (0);
}

int	render(t_data *data)
{
	render_background(data, BACKGROUND_COLOR);
	render_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (1);
}