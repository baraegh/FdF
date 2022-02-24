

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

# define W_WIDTH 1000
# define W_HEIGHT 1000
# define COLOR 0xB8405E
# define COLOR_Z 0xEEE6CE
# define ERROR -1


void	read_file(t_data *data, char *file_path);
int		display(t_data data);
int		render(t_data *data);
void	img_pix_put(t_img *img, t_point p, int color);
int		handle_no_event(void *data);
int		handle_input(int keysym, t_data *data);
int		handle_mouse(int x, int y, void *data);
void	draw_line_bresenham(t_data *data, t_point b_p, t_point e_p);
void	isometric_proj(t_point	*p);
void	render_map(t_data *data);

#endif