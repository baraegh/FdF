/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:18:43 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/06 22:20:44 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	view_init(t_data *data)
{
	data->view.proj = ISO;
	data->view.x_offset = 0;
	data->view.y_offset = 0;
	data->view.x_teta = 0;
	data->view.y_teta = 0;
	data->view.z_teta = 0;
}

void	rotate_x(int *y, int *z, double teta)
{
	int		tmp_y;

	tmp_y = *y;
	*y = tmp_y * cos(teta) + *z * sin(teta);
	*z = -tmp_y * sin(teta) + *z * cos(teta);
}

void	rotate_y(int *x, int *z, double teta)
{
	int		tmp_x;

	tmp_x = *x;
	*x = tmp_x * cos(teta) + *z * sin(teta);
	*z = -tmp_x * sin(teta) + *z * cos(teta);
}

void	rotate_z(int *x, int *y, double teta)
{
	int		tmp_x;

	tmp_x = *x;
	*x = tmp_x * cos(teta) - *y * sin(teta);
	*y = tmp_x * sin(teta) + *y * cos(teta);
}
