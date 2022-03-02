/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 02:16:54 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/02 22:59:13 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	terminate(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(0);
}

void	free_arr(char **arr, char *msg)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	if (msg)
		terminate(msg);
}

void	check_line(char *line, int fd)
{
	int	i;

	if (!line)
	{
		close(fd);
		terminate(ERR_MAP);
	}
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			return ;
		i++;
	}
	close(fd);
	terminate(ERR_MAP);
}

void	free_z_matrix(char ***matrix, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			free(matrix[i][j]);
			j++;
		}
		free(matrix[i]);
		i++;
	}
	free(matrix);
	if (line)
		free(line);
	terminate(ERR_SET_MATRIX);
}
