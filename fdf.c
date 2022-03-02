/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:27:01 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/02 01:48:33 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void	img_pix_put(t_img *img, t_point p, int color)
// {
// 	char	*pixel;

// 	if (p.x < WIDTH & p.y >= 0 && p.y < HEIGHT)
// 	{
// 		pixel = img->addr + (p.y * img->line_len + p.x * (img->bpp / 8));
// 		*(int *)pixel = color;
// 	}
// }

void	img_pix_put(t_img *img, t_point p, int color)
{
	char    *pixel;
	int		i;

	if (p.x < WIDTH & p.y >= 0 && p.y < HEIGHT)
	{
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
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		read_file(&data, av[1]);
		printf("w: %d, h: %d zoom: %d\n", data.map.width, data.map.heigth, data.zoom);
		if (display(data, av[1]))
			return (0);
	}
	return (0);
}