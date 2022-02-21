/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:43:00 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/02/20 00:14:24 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 100

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(char *s, char c);
char	*ft_copy(char *line, char *str_saved);

#endif
