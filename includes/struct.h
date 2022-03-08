/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:28:00 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/08 18:44:43 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	int	width;
	int	heigth;
}	t_map;

typedef struct s_view
{
	char	proj;
	int		zoom;
	int		x_offset;
	int		y_offset;
	double	x_teta;
	double	y_teta;
	double	z_teta;
}	t_view;

typedef struct s_data
{
	t_map	map;
	t_view	view;
	char	***z_matrix;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	char	**str;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	org_z;
	int	color;
	int	color_is_set;
}	t_point;

typedef struct s_var
{
	int		dx;
	int		dy;
	int		step_x;
	int		step_y;
	int		err;
	int		err_i;
	t_point	p;
}	t_var;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

#endif