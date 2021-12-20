/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:43:16 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/20 11:51:01 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		win_width;
	int		win_height;
	char	*addr;
	int		**texture;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	xmax;
	double	xmin;
	double	ymax;
	double	ymin;
}				t_vars;

#endif