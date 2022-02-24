

#include "header.h"

t_var	set_values(t_data *data, t_point *b_p, t_point *e_p)
{	
	t_var var;

	var.dx = abs(e_p->x - b_p->x);
	var.dy = -abs(e_p->y - b_p->y);
	var.step_x = 1;
	var.step_y = 1;
	if (b_p->x > e_p->x)
		var.step_x = -1;
	if (b_p->y > e_p->y)
		var.step_y = -1;
	b_p->x *= data->zoom;
	b_p->y *= data->zoom;
	e_p->x *= data->zoom;
	e_p->y *= data->zoom;
	return (var);
}

int	get_color(t_point b_p, t_point e_p)
{
	(void) e_p;

	if (b_p.z == 0)
		return (COLOR);
	return (b_p.color);
}

void	draw_line_bresenham(t_data *data, t_point b_p, t_point e_p)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;
	int		i;
	
	b_p.x *= data->zoom;
	b_p.y *= data->zoom;
	e_p.x *= data->zoom;
	e_p.y *= data->zoom;
	isometric_proj(&b_p);
	isometric_proj(&e_p);

	delta_x = e_p.x - b_p.x;
	delta_y = e_p.y - b_p.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = b_p.x;
	pixel_y = b_p.y;
	i = 0;
	while (i < pixels)
	{
		img_pix_put(&data->img, (t_point){pixel_x, pixel_y, 0, 0}, get_color(b_p, e_p));
		pixel_x += delta_x;
		pixel_y += delta_y;
		i++;
	}
}

// void	draw_line_bresenham(t_data *data, t_point b_p, t_point e_p)
// {
// 	t_var	var;
// 	int		err;
// 	// int		err_i;

// 	var = set_values(data, &b_p, &e_p);
// 	isometric_proj(&b_p);
// 	isometric_proj(&e_p);
// 	err = var.dx + var.dy;
	// printf("err: %d, var.dx: %d, var.dy: %d\n-----------\n", err, var.dx, var.dy);
	// while (1)
	// {
	// 	img_pix_put(&data->img, b_p, get_color(b_p, e_p));
	// 	err_i = 2 * err;
	// 	if (err_i >= var.dy)
	// 	{
	// 		printf("here y");
	// 		if (b_p.x >= e_p.x) 
	// 			break ;
	// 		err += var.dy;
	// 		b_p.x += var.step_x;
	// 	}
	// 	if (err_i >= var.dx)
	// 	{
	// 		printf("here x");
	// 		if (b_p.y >= e_p.y)
	// 			break ;
	// 		err += var.dx;
	// 		b_p.y += var.step_y;
	// 	}
	// }
// }
