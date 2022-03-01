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

int	get_color(t_point b_p, t_point e_p)
{
	(void) e_p;

	if (b_p.color_is_set == 0)
		return (COLOR);
	return (b_p.color);
}

t_var	set_values(t_data *data, t_point *b_p, t_point *e_p)
{	
	t_var var;
	(void) data;
	
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

	var = set_values(data, &b_p, &e_p);
	err = var.dx + var.dy;
	while (1)
	{
		// printf("color: %d\n", b_p.color);
		img_pix_put(&data->img, b_p, b_p.color);
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

