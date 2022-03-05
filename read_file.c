/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:27:13 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/05 01:20:43 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_width(char *s)
{
	char	**tmp;
	int		width;
	int		i;

	tmp = ft_split(s, ' ');
	width = 0;
	i = 0;
	while (tmp[i])
	{
		if (ft_strncmp(tmp[i], "\n", 1))
			width++;
		i++;
	}
	free_arr(tmp, NULL);
	return (width);
}

int	get_heigth(int fd, char *line, int width)
{
	int	heigth;
	
	heigth = 0;
	while (line != NULL)
	{
		check_line(line, fd);
		if (width != get_width(line))
		{
			free(line);
			terminate(ERR_MAP);
		}
		heigth++;
		free(line);
		line = get_next_line(fd);
	}
	return(heigth);
}

void	get_heigth_width(t_data *data, char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	check_line(line, fd);
	data->map.width = get_width(line);
	data->map.heigth = get_heigth(fd, line, data->map.width);
	close(fd);
}

char	***set_matrix(char * file_path, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_path, O_RDONLY);
	data->z_matrix = (char ***)malloc(sizeof(char **) * data->map.heigth + 1);
	if (!data->z_matrix)
		return (0);
	i = 0;
	while (i < data->map.heigth)
	{
		line = get_next_line(fd);
		if (!line)
			free_matrix(data->z_matrix, line);
		data->z_matrix[i] = ft_split(line, ' ');
		if (!data->z_matrix[i])
			free_matrix(data->z_matrix, ERR_RENDER); 
		free(line);
		i++;
	}
	close(fd);
	return (data->z_matrix);
}

void	read_file(t_data *data, char *file_path)
{
	get_heigth_width(data, file_path);
	data->zoom = FT_MIN(WIDTH / data->map.width / 2,
		HEIGHT / data->map.heigth / 2);
	if (!set_matrix(file_path, data))
		terminate(ERR_SET_MATRIX);
}