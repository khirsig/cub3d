/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:58:00 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/10 10:10:09 by khirsig          ###   ########.fr       */
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
}				t_data;
/*
** -----------------------------------------------------------------------------
** Function prototypes
*/
int	parse_map(t_data *data, char *file);
int	error_map(t_data *data, char **map);

#endif