/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:27:01 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/06 22:08:55 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	img_pix_put(t_img *img, t_point p, int color)
{
	char	*pixel;
	int		i;

	if (p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT)
	{
		i = img->bpp - 8;
		pixel = img->addr + (p.y * img->line_len + p.x * (img->bpp / 8));
		while (i >= 0)
		{
			if (img->endian != 0)
				*pixel++ = (color >> i) & 0xFF;
			else
				*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
			i -= 8;
		}
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	if (ac == 2)
	{	
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			terminate(ERR_MAP_READING);
		close(fd);
		read_file(&data, av[1]);
		if (display(data, av[1]))
			terminate(ERR_MAP_READING);
	}
	else
		terminate(ERR_USAGE);
	return (0);
}
