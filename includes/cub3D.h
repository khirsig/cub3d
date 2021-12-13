/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:58:00 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/13 15:58:31 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
** -----------------------------------------------------------------------------
** Includes
*/
# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include "maze.h"
# include "player.h"
# include "vars.h"
# include "ray.h"
/*
** -----------------------------------------------------------------------------
** Structs and typedef.
*/
typedef struct s_data {
	t_maze		maze;
	t_player	player;
	t_vars		vars;
	t_ray		ray;
	int			file;
	int			x_length;
	int			y_length;
	int			read_length;
}				t_data;

/*
** -----------------------------------------------------------------------------
** Function prototypes
*/
int	parse_map(t_data *data, char *file);
int	error_map(t_data *data, char **map);
int	map_x_length(t_data *data, char *file);
int	map_y_length(t_data *data, char *file);
/*
** Minimap
*/
int		minimap(t_data *data);
/*
** Loop
*/
int		gameloop(t_data *data);
/*
** Parse color
*/
int		parse_part_1(int fd, t_data *data);
void	parse_color(char *str, int i, t_data *data);

/*
** Draw image
*/
void	fill_player(t_data *data);
void	draw_view(t_data *data);
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);

#endif