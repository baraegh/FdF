
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

void	draw_h(t_data *data, int x, int y)
{
	t_point p1;
	t_point p2;

	p1 = get_point(x, y, data->z_matrix[y][x]);
	p2 = get_point(x + 1, y, data->z_matrix[y][x + 1]);
	draw_line_bresenham(data, p1 , p2);
}

void	draw_v(t_data *data, int x, int y)
{
	t_point p1;
	t_point p2;

	p1 = get_point(x, y, data->z_matrix[y][x]);
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
			if (x < data->width - 1)
				draw_h(data, x, y);
			if (y < data->heigth - 1)
				draw_v(data, x, y);
			x++;
		}
		y++;
	}
}