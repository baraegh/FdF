/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:28:00 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/01 03:01:54 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	int	width;
	int	heigth;
} t_map;

typedef struct s_data
{
	t_map	map;
	char	***z_matrix;
	int		zoom;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	color_is_set;
} t_point;

typedef struct s_var
{
	int dx;
	int dy;
	int step_x;
	int step_y;
} t_var;


typedef struct s_rect
{
	t_point	p;
	int		width;
	int		height;
	int		color;
} t_rect;

typedef struct s_triangle
{
	t_point	p0;
	t_point	p1;
	t_point	p2;
	int		height;
	int		color;
} t_triangle;


# endif