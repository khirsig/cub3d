/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:43:16 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 12:57:00 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

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

#endif