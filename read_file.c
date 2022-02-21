
#include "header.h"

int	get_heigth(char *file_path)
{
	int		fd;
	int		heigth;
	char	*line;

	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	heigth = 0;
	while (line != NULL)
	{
		free(line);
		heigth++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (heigth);
}

int	get_width(char *file_path)
{
	int		fd;
	char	*line;
	int		width;
	char	**tmp;

	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	tmp = ft_split(line, ' ');
	if (!tmp)
	{
		free(line);
		close(fd);
		return (0);
	}
	width = 0;
	while (tmp[width] != NULL)
		width++;
	free(tmp);
	free(line);
	close(fd);
	return (width);
}

char	***get_matrix(char * file_path, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_path, O_RDONLY);
	data->z_matrix = (char ***)malloc(sizeof(char **) * data->height + 1);
	// if (!data->z_matrix)
		/*return*/
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		// if (!line)
			// 	return
		data->z_matrix[i] = (char **)malloc(sizeof(char *) * data->width + 1);
		data->z_matrix[i] = ft_split(line, ' ');
		free(line);
		i++;
	}
	close(fd);
	return (data->z_matrix);
}

void	read_file(t_data *data, char *file_path)
{
	data->width = get_width(file_path);
	// if (data->width == 0)
		// return
	data->height = get_heigth(file_path);
	// if (data->heigth == 0)
		// return
	get_matrix(file_path, data);
	// if (!data->z_matrix)
		// return
}
