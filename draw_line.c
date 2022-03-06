/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:01:02 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/06 22:05:58 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
