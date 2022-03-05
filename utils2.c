/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 01:23:38 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/04 22:45:40 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	zoom(int key_code, t_data *data)
{
	if (key_code  == KEY_PLUS)
		data->zoom++;
	else
		data->zoom--;
	if (data->zoom < 1)
		data->zoom = 1;
	render_map(data);
}