/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:25:42 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/08 18:55:59 by eel-ghan         ###   ########.fr       */
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

# define HEIGHT				1080
# define WIDTH				1500
# define BACKGROUND_COLOR	0x313552
# define DEFAULT_COLOR		0xB8405E
# define Z_COLOR			0xEEE6CE
# define ISO				'I'
# define PARALLEL			'P'

void	read_file(t_data *data, char *file_path);
void	check_line(char *line, int fd);
int		display(t_data data, char *file_path);
int		render(t_data *data);
void	render_map(t_data *data);
int		get_color(t_point b_p, t_point e_p, t_point c_p);
int		hex_to_int(char *hex);
void	draw_line_bresenham(t_data *data, t_point b_p, t_point e_p);
void	img_pix_put(t_img *img, t_point p, int color);
void	hooks(int (*render)(t_data *), t_data data);
void	zoom(int key_code, t_data *data);
void	move_map(int key_code, t_data *data);
void	terminate(char *msg);
void	free_arr(char **arr, char *msg);
void	free_matrix(char ***matrix, char *line);
void	free_data(t_data *data, char *msg);
void	view_init(t_data *data);
void	rotate_x(int *y, int *z, double teta);
void	rotate_y(int *x, int *z, double teta);
void	rotate_z(int *x, int *y, double teta);
void	rotate_map(int key_code, t_data *data);
void	project(t_point *p, t_data *data);
void	set_project(int key_code, t_data *data);
int		ft_min(int a, int b);

#endif