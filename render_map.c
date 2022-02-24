
#include "header.h"

t_point	get_point(int x, int y, char *s)
{
	t_point p;
	char	**str = NULL;

	p.x = x;
	p.y = y;
	if (ft_strchr(s, ','))
	{
		str = ft_split(s, ',');
		p.z = ft_atoi(str[0]);
		p.color = (int)str[1];
	}
	else
	{
		p.z = ft_atoi(s);
		p.color = COLOR_Z;
	}
	return (p);
}

void	draw_h_v(t_data *data, int x, int y)
{
	t_point p1;
	t_point p2;

	p1 = get_point(x, y, data->z_matrix[y][x]);
	p2 = get_point(x + 1, y, data->z_matrix[y][x + 1]);
	draw_line_bresenham(data, p1 , p2);
	p2 = get_point(x, y + 1, data->z_matrix[y + 1][x]);
	draw_line_bresenham(data, p1 , p2);
}

void	render_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->heigth)
	{
		x = 0;
		while (x < data->width)
		{
			if (x + 1 == data->width - 1)
				break ;
			draw_h_v(data, x, y);
			x++;
		}
		draw_h_v(data, x, y);
		if (y + 1 == data->heigth - 1)
			return ;
		y++;
	}
}