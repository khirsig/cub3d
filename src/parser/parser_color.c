/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:57:05 by jhagedor          #+#    #+#             */
/*   Updated: 2022/01/17 12:43:16 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
Checks input for the floor and ceiling (helper function).
*/

void	check_color_str_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ',' && str[i] != ' ')
			ft_putstr_error("Error\n");
		i++;
	}
}

/*
Checks input for the floor and ceiling.
*/

void	check_color_str(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	check_color_str_char(str);
	if (str[i] != ' ')
		ft_putstr_error("Error\n");
	while (count <= 5)
	{
		while (str[i] == ' ')
			i++;
		if (count % 2 == 0 && str[i] != ',')
			ft_putstr_error("Error\n");
		if (count % 2 == 1 && (str[i] < '0' || str[i] > '9'))
			ft_putstr_error("Error\n");
		if (str[i] == ',')
			i++;
		else
		{
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		count++;
	}
}

/*
Parses color information for the floor and ceiling.
*/

void	parser_color(char *str, int i, t_data *data)
{
	int		r;
	int		g;
	int		b;
	char	c;

	c = str[i];
	check_color_str(&str[i + 1]);
	r = ft_atoi(&str[i + 1]);
	while (str[i] != ',')
		i++;
	g = ft_atoi(&str[i + 1]);
	i++;
	while (str[i] != ',')
		i++;
	b = ft_atoi(&str[i + 1]);
	if (r > 255 || g > 255 || b > 255)
		ft_putstr_error("Error\n");
	if (c == 'F')
		data->maze.floor_color = 65536 * r + 256 * g + b;
	else
		data->maze.ceiling_color = 65536 * r + 256 * g + b;
}
