/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:30:57 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/07 15:45:23 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static	int	parser_map_x_length_get(int fd, char *str)
{
	int		highest_count;
	int		count;

	str = get_next_line_2(fd);
	while (str != NULL && str[0] == '\n')
	{
		free(str);
		str = get_next_line_2(fd);
	}
	highest_count = ft_strlen(str) - 1;
	while (str != NULL)
	{
		free(str);
		str = get_next_line_2(fd);
		if (str == NULL)
			break ;
		count = ft_strlen(str) - 1;
		if (highest_count < count)
			highest_count = count;
	}
	return (highest_count);
}

/*
** Opens the file again and skips newlines.
** Returns the maximum x-length of the map.
*/
int	parser_map_x_length(t_data *data, char *file)
{
	char	*str;
	int		count;
	int		fd;
	int		index;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	index = 0;
	while (index < data->read_length)
	{
		str = get_next_line_2(fd);
		free(str);
		index++;
	}
	count = parser_map_x_length_get(fd, str);
	close(fd);
	return (count);
}

static int	parser_map_y_length_get(int fd, char *str)
{
	int	count;

	count = 0;
	str = get_next_line_2(fd);
	while (str != NULL && str[0] == '\n')
	{
		free(str);
		str = get_next_line_2(fd);
	}
	while (str != NULL)
	{
		free(str);
		count++;
		str = get_next_line_2(fd);
	}
	free(str);
	return (count);
}

/*
** Opens the file again and skips newlines.
** Returns the maximum y-length of the map.
*/
int	parser_map_y_length(t_data *data, char *file)
{
	char	*str;
	int		count;
	int		fd;
	int		index;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	index = 0;
	while (index < data->read_length)
	{
		str = get_next_line_2(fd);
		free(str);
		index++;
	}
	count = parser_map_y_length_get(fd, str);
	close(fd);
	return (count);
}
