/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:26:06 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/03 02:12:23 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	close_window(t_data *data)
{	
	(void) data;

	exit(0);
	return (1);
}

int	handle_keypress(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		close_window(data);
	else if (key_code == KEY_PLUS || key_code == KEY_MINUS)
		zoom(key_code, data);
	return (1);
}

int	handle_mouse(int x, int y, void *data)
{
	(void)	data;
	(void)	x;
	(void)	y;
	
	return (1);
}

void	hooks(int (*render)(t_data *), t_data data)
{
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_hook(data.win_ptr, EVENT_KEY_PRESS, KEY_PRESS_MASK, &handle_keypress, &data);
	mlx_hook(data.win_ptr, EVENT_CLOSE, 0, &close_window, &data);
}