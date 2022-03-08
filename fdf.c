/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:27:01 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/08 18:55:40 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
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
