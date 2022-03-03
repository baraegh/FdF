/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:25:42 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/03 01:31:47 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "mlx.h"
# include "includes/mlx_keys.h"
# include "includes/struct.h"
# include "includes/error.h"
# include "get_next_line/get_next_line.h"
# include "Libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
/* TO BE DELETED */
# include <stdio.h>
/*///////////////*/

# define HEIGHT				1080
# define WIDTH				1500
# define BACKGROUND_COLOR	0x313552
# define DEFAULT_COLOR		0xB8405E
# define Z_COLOR			0xEEE6CE

void	read_file(t_data *data, char *file_path);
int		display(t_data data, char* file_path);
int 	render(t_data *data);
void	img_pix_put(t_img *img, t_point p, int color);
int		handle_mouse(int x, int y, void *data);
void	draw_line_bresenham(t_data *data, t_point b_p, t_point e_p);
void	render_map(t_data *data);
int		get_color(t_point b_p, t_point e_p);
void	terminate(char *msg);
void	free_arr(char **arr, char *msg);
void	check_line(char *line, int fd);
void	free_z_matrix(char ***matrix, char *line);
void	hooks(int (*render)(t_data *), t_data data);
void	zoom(int key_code, t_data *data);

#endif