/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:01:02 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/07 00:09:09 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	img_pix_put(t_img *img, t_point p, int color)
{
	char	*pixel;
	int		i;

	if (p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT)
	{
		i = img->bpp - 8;
		pixel = img->addr + (p.y * img->line_len + p.x * (img->bpp / 8));
		while (i >= 0)
		{
			if (img->endian != 0)
				*pixel++ = (color >> i) & 0xFF;
			else
				*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
			i -= 8;
		}
	}
}

t_var	set_values(t_point *b_p, t_point *e_p)
{	
	t_var	var;

	var.dx = abs(e_p->x - b_p->x);
	var.dy = -abs(e_p->y - b_p->y);
	var.step_x = 1;
	var.step_y = 1;
	if (b_p->x > e_p->x)
		var.step_x = -1;
	if (b_p->y > e_p->y)
		var.step_y = -1;
	var.err = var.dx + var.dy;
	var.p = *b_p;
	return (var);
}

void	draw_line_bresenham(t_data *data, t_point b_p, t_point e_p)
{
	t_var	var;

	var = set_values(&b_p, &e_p);
	while (1)
	{
		img_pix_put(&data->img, var.p, get_color(b_p, e_p, var.p));
		var.err_i = 2 * var.err;
		if (var.err_i >= var.dy)
		{
			if (var.p.x == e_p.x)
				break ;
			var.err += var.dy;
			var.p.x += var.step_x;
		}
		if (var.err_i <= var.dx)
		{
			if (var.p.y == e_p.y)
				break ;
			var.err += var.dx;
			var.p.y += var.step_y;
		}
	}
}
