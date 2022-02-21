

#include "header.h"

int	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			img_pix_put(img, (t_point){j++, i, 500}, color);
		}
		i++;
	}
	return (0);
}

void	isometric_proj(t_point	*p)
{
	t_point	tmp_p;

	tmp_p.x = p->x;
	tmp_p.y = p->y;
	p->x = (tmp_p.x - tmp_p.y) * cos(0.523599);
	p->y = (tmp_p.x + tmp_p.y) * sin(0.523599) - p->z;
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (0);
	render_background(&data->img, 0x313552);
	draw_line_bresenham(&data->img, (t_point){500, 285, 0}, (t_point){500, 720, 0}, 0x2EB086);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (1);
}