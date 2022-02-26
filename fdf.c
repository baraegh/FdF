

#include "header.h"

// void	img_pix_put(t_img *img, t_point p, int color)
// {
// 	char	*pixel;
// 	pixel = img->addr + (p.y * img->line_len + p.x * (img->bpp / 8));
// 	*(int *)pixel = color;
// }

void	img_pix_put(t_img *img, t_point p, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (p.y * img->line_len + p.x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	get_data_zoom(t_data *data)
{
	if (data->heigth <= 21)
		data->zoom = 20;
	else if (data->heigth <= 101 
		&& data->heigth > 21)
		data->zoom= 10;
	else if (data->heigth <= 150 
		&& data->heigth > 101)
		data->zoom = 5;
	else if (data->heigth <= 501 
		&& data->heigth > 150)
		data->zoom = 2;
	else
		data->zoom = 1;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		read_file(&data, av[1]);
		get_data_zoom(&data);
		if (display(data))
			return (0);
	}
	return (0);
}