/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:27:13 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/01 02:23:09 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_width(char *s)
{
	char	**tmp;
	int		width;

	tmp = ft_split(s, ' ');
	width = 0;
	while (tmp[width])
	{
		free(tmp[width]);
		width++;
	}
	free(tmp);
	return (width);
}

int	get_heigth(int fd, char *line)
{
	int	heigth;

	heigth = 0;
	while (line != NULL)
	{
		heigth++;
		free(line);
		line = get_next_line(fd);
	}
	return(heigth);
}

int	get_heigth_width(t_data *data, char *file_path)
{
	int		fd;
	char	*line;
	(void) data;

	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	data->map.width = get_width(line);
	data->map.heigth = get_heigth(fd, line);
	close(fd);
	return (1);
}

char	***set_matrix(char * file_path, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_path, O_RDONLY);
	data->z_matrix = (char ***)malloc(sizeof(char **) * data->map.heigth + 1);
	// if (!data->z_matrix)
		/*return*/
	i = 0;
	while (i < data->map.heigth)
	{
		line = get_next_line(fd);
		// if (!line)
			// 	return
		data->z_matrix[i] = (char **)malloc(sizeof(char *) * data->map.width + 1);
		data->z_matrix[i] = ft_split(line, ' ');
		free(line);
		i++;
	}
	close(fd);
	return (data->z_matrix);
}

void	read_file(t_data *data, char *file_path)
{
	get_heigth_width(data, file_path);
	// if (get_heigth_width(data, file_path))
	// 	return
	data->zoom = FT_MIN(WIDTH / data->map.width / 2,
		HEIGHT / data->map.heigth / 2);
	set_matrix(file_path, data);
	// if (!data->z_matrix)
		// return
}
