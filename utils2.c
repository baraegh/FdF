/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 01:23:38 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/06 03:42:31 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	zoom(int key_code, t_data *data)
{
	if (key_code  == KEY_PLUS)
		data->view.zoom++;
	else
		data->view.zoom--;
	if (data->view.zoom < 1)
		data->view.zoom = 1;
	render_map(data);
}

void	move_map(int key_code, t_data *data)
{
	if (key_code == KEY_UP)
		data->view.y_offset -= 10;
	else if (key_code == KEY_DOWN)
		data->view.y_offset += 10;
	else if (key_code == KEY_RIGHT)
		data->view.x_offset+= 10;
	else
		data->view.x_offset-= 10;
	render_map(data);
}

void	rotate_map(int key_code, t_data *data)
{
	if (key_code == KEY_PAD_2)
		data->view.x_teta += 0.5;
	else if (key_code == KEY_PAD_8)
		data->view.x_teta -= 0.5;
	else if (key_code == KEY_PAD_4)
		data->view.y_teta -= 0.5;
	else if (key_code == KEY_PAD_6)
		data->view.y_teta += 0.5;
	else if (key_code == KEY_PAD_1)
		data->view.z_teta -= 0.5;
	else if (key_code == KEY_PAD_3)
		data->view.z_teta += 0.5;
	render_map(data);
}

void	set_project(int	key_code, t_data *data)
{
	if (key_code == KEY_P)
		data->view.proj = PARALLEL;
	else
		data->view.proj = ISO;
}