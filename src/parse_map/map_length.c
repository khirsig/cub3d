/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:30:57 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/10 10:32:16 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	map_x_length(char *file)
{
	char	*str;
	int		highest_count;
	int		count;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	highest_count = 0;
	str = get_next_line(fd);
	while (str != NULL && str[0] == '\n')
	{
		free(str);
		str = get_next_line(fd);
	}
	highest_count = ft_strlen(str) - 1;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		count = ft_strlen(str) - 1;
		if (highest_count < count)
			highest_count = count;
	}
	free(str);
	close(fd);
	return (highest_count);
}

int	map_y_length(char *file)
{
	char	*str;
	int		count;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	str = get_next_line(fd);
	while (str != NULL && str[0] == '\n')
	{
		free(str);
		str = get_next_line(fd);
	}
	while (str != NULL)
	{
		free(str);
		count++;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (count);
}
