

#include "header.h"

int	draw_line_bresenham(t_img *img, t_point b_p, t_point e_p, int color)
{
	int		dx;
	int		dy;
	int		err;
	int		err_i;
	int		step_x;
	int		step_y;

	dx = abs(e_p.x - b_p.x);
	dy = -abs(e_p.y - b_p.y);
	step_x = 1;
	step_y = 1;
	if (b_p.x > e_p.x)
		step_x = -1;
	if (b_p.y > e_p.y)
		step_y = -1;
	err = dx + dy;
	while (1)
	{
		img_pix_put(img, b_p, color);
		err_i = 2 * err;
		if (err_i >= dy)
		{
			if (b_p.x == e_p.x) 
				break ;
			err += dy;
			b_p.x += step_x;
		}
		if (err_i <= dx)
		{
			if (b_p.y == e_p.y)
				break ;
			err += dx;
			b_p.y += step_y;
		}
	}
	return (0);
}
