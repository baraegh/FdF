/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:25:42 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/02 00:21:02 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "mlx.h"
# include "includes/mlx_keys.h"
# include "includes/struct.h"
# include "get_next_line/get_next_line.h"
# include "Libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
/* TO BE DELETED */
# include <stdio.h>
/*///////////////*/

# define HEIGHT	1080
# define WIDTH	1500
# define DEFAULT_COLOR 0xB8405E
# define Z_COLOR 0xEEE6CE
# define ERROR -1
#define TILE_Y 30
# define TILE_X 30

void	read_file(t_data *data, char *file_path);
int		display(t_data data, char* file_path);
int		render(t_data *data);
void	img_pix_put(t_img *img, t_point p, int color);
int		handle_no_event(void *data);
int		handle_input(int keysym, t_data *data);
int		handle_mouse(int x, int y, void *data);
void	draw_line_bresenham(t_data *data, t_point b_p, t_point e_p);
void	isometric_proj(t_point	*p, t_data *data);
void	render_map(t_data *data);
int		get_color(t_point b_p, t_point e_p);


#endif