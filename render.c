/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:27:25 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/01 03:04:18 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			img_pix_put(&data->img, (t_point){j++, i, 0, 0, 0}, color);
		}
		i++;
	}
	return (0);
}

void	isometric_proj(t_point	*p, t_data *data)
{
	(void) data;

	p->x = (p->x - p->y) * cos(0.8);
	p->y = (p->x + p->y) * sin(0.8) - (p->z * data->zoom);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (0);
	render_background(data, 0x313552);
	render_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (1);
}