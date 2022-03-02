/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27b_ 6:26:50 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/02/28 17:25:50 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_var	set_values(t_point *b_p, t_point *e_p)
{	
	t_var var;
	
	var.dx = abs(e_p->x - b_p->x);
	var.dy = -abs(e_p->y - b_p->y);
	var.step_x = 1;
	var.step_y = 1;
	if (b_p->x > e_p->x)
		var.step_x = -1;
	if (b_p->y > e_p->y)
		var.step_y = -1;
	return (var);
}

void	draw_line_bresenham(t_data *data, t_point b_p, t_point e_p)
{
	t_var	var;
	int		err;
	int		err_i;

	var = set_values(&b_p, &e_p);
	err = var.dx + var.dy;
	while (1)
	{
		img_pix_put(&data->img, b_p, get_color(b_p, e_p));
		err_i = 2 * err;
		if (err_i >= var.dy)
		{
			if (b_p.x == e_p.x)
				break ;
			err += var.dy;
			b_p.x += var.step_x;
		}
		if (err_i <= var.dx)
		{
			if (b_p.y == e_p.y)
				break ;
			err += var.dx;
			b_p.y += var.step_y;
		}
	}
}

