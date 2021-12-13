/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:58:00 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/13 13:40:11 by khirsig          ###   ########.fr       */
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
/*
** -----------------------------------------------------------------------------
** Structs and typedef.
*/
typedef struct s_data {
	t_maze	maze;
	int		file;
	int		x_length;
	int		y_length;
	int		read_length;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	xmax;
	double	xmin;
	double	ymax;
	double	ymin;

	double	x;
	double	y;
	int		fractal_type;
	double		julia_real;
	double		julia_imag;
	int			xoff;
	int			yoff;
}				t_vars;

typedef struct s_game {
	double	x_pos;
	double	y_pos;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}				t_game;
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
int	minimap(t_data *data, t_vars *vars, t_game *game);
int	keyhook(int keystroke, t_vars *vars);
int	player_move(int keystroke, t_game *game);
/*
** Parse color
*/
int		parse_part_1(int fd, t_data *data);
void	parse_color(char *str, int i, t_data *data);

/*
** Draw image
*/
void	fill_game(t_data *data, t_game *game);
void	calculate_dist(t_data *data, t_game *game, t_vars *vars);
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);

#endif