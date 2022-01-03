/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:07:41 by jhagedor          #+#    #+#             */
/*   Updated: 2022/01/03 10:24:34 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
Malloc memory and save clean string
*/

char	*get_clean_strings(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = malloc(ft_strlen(str) + 1);
	while (str[i] == ' ')
		i++;
	while (str[i] != '\n')
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = 0;
	return (ret);
}

/*
Parses information for the texture.
*/

void	parse_texture(char *str, int i, t_data *data)
{
	if (str[i] == 'N' && str[i + 1] == 'O')
		data->maze.north_texture = get_clean_strings(&str[i + 2]);
	else if (str[i] == 'S' && str[i + 1] == 'O')
		data->maze.south_texture = get_clean_strings(&str[i + 2]);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		data->maze.west_texture = get_clean_strings(&str[i + 2]);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		data->maze.east_texture = get_clean_strings(&str[i + 2]);
	else
		ft_putstr_fd("Error\n", 2);
}

/*
Checks input of new line and parses relevant information.
*/

int	check_line(char *str, t_data *data)
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
		parser_color(str, i, data);
		return (2);
	}
	else if (str[i] == '\n')
		return (3);
	return (0);
}

/*
1) Reads new lines until the four paths and the two colors are parsed.
2) Checks for wrong input values at the end.
*/

void	parser_color_wall(t_data *data)
{
	int		lines;
	int		count;
	int		i;
	char	*str;

	lines = 0;
	count = 0;
	while (1)
	{
		str = get_next_line(data->file);
		if (str == NULL || count == 6)
		{
			if (count < 6)
				ft_putstr_fd("Error\n", 2);
			break ;
		}
		i = check_line(str, data);
		if (i == 0)
			ft_putstr_fd("Error\n", 2);
		else if (i == 1 || i == 2)
			count++;
		lines++;
	}
	data->read_length = lines;
}
