/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:07:41 by jhagedor          #+#    #+#             */
/*   Updated: 2021/12/10 17:58:29 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
Parses information for the texture.
*/

void	parse_texture(char *str, int i, t_data *data)
{
	if (str[i] == 'N' && str[i + 1] == 'O')
		data->maze.north_texture = &str[i + 2];
	else if (str[i] == 'S' && str[i + 1] == 'O')
		data->maze.south_texture = &str[i + 2];
	else if (str[i] == 'W' && str[i + 1] == 'E')
		data->maze.west_texture = &str[i + 2];
	else if (str[i] == 'E' && str[i + 1] == 'A')
		data->maze.east_texture = &str[i + 2];
	else
		ft_putstr_fd("Error\n", 2);
}

/*
Checks input of new line and parses relevant information.
*/

int	check_next_line(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
	{
		parse_texture(str, i, data);
		return (1);
	}
	else if (str[i] == 'F' || str[i] == 'C')
	{
		parse_color(str, i, data);
		return (2);
	}
	else if (str[i] == '\n')
		return (3);
	return (0);
}

/*
1) Checks if color values are between 0 and 255.
2) Checks if ceiling and floor colors are provided.
*/

void	check_parsing(t_data *data)
{
	if (data->maze.floor.r > 255
		|| data->maze.floor.b > 255
		|| data->maze.floor.g > 255)
		ft_putstr_fd("Error\n", 2);
	if (data->maze.ceiling.r > 255
		||data->maze.ceiling.b > 255
		||data->maze.ceiling.g > 255)
		ft_putstr_fd("Error\n", 2);
	if (data->maze.floor.check == 0
		||data->maze.ceiling.check == 0)
		ft_putstr_fd("Error\n", 2);
}

/*
1) Reads new lines until the four paths and the two colors are parsed.
2) Checks for wrong input values at the end.
*/

int	parse_part_1(int fd, t_data *data)
{
	int		lines;
	int		count;
	int		i;
	char	*str;

	lines = 0;
	count = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL || count == 6)
		{
			if (count < 6)
				ft_putstr_fd("Error\n", 2);
			break ;
		}
		i = check_next_line(str, data);
		if (i == 0)
			ft_putstr_fd("Error\n", 2);
		else if (i == 1 || i == 2)
			count++;
		lines++;
	}
	check_parsing(data);
	return (lines);
}
