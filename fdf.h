/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 20:31:59 by rramirez          #+#    #+#             */
/*   Updated: 2017/06/26 20:32:20 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# define RED 0x00FF33FF
# define WHITE 0x00FFFFFF
# define BLUE 0X00242cf8
# define PINK 0x006600FF
# define ESC 53

typedef	struct			s_values
{
	float				offset;
	float				threshold;
	float				delta;
	float				adjust;
}						t_values;

typedef	struct			s_cartp
{
	float				x;
	float				y;
	float				z;
}						t_cartp;

typedef struct			s_bio
{
	int					right;
	float				cur_z;
	float				next_z;
	float				x1;
	float				x2;
	float				y1;
	float				y2;
	int					gap;
	int					big;
	float				rise;
	float				run;
	float				slope;
	float				max;
	float				smax;
	void				*mlx;
	void				*window;
	int					midx;
	int					midy;
	t_cartp				**cart;
}						t_bio;

typedef struct			s_fdf
{
	int					win_x;
	int					win_y;
	int					zmax;
	int					zmin;
	int					width;
	int					height;
	int					**map;
	char				**coor;
	char				*line;
	char				*str;
}						t_fdf;

void					ft_set_v(t_bio *bio, t_values *values);
void					file_check(t_fdf *size, int argc, char **argv);
void					ft_valid_file(int fd, int w, t_fdf *size);

void					save_file(char **argv, t_fdf *size);
void					coordinates(int fd, char **argv, t_fdf **size);
void					value_z(t_fdf **size, int x);
t_bio					*make_env(t_fdf size);
t_cartp					**ft_make_cart(t_bio **bio, t_fdf size);
void					draw_pieces(t_bio *bio, t_fdf size);
void					translate(t_bio **bio, t_fdf size);
void					ft_values(t_bio **bio, int i, int j, t_fdf size);

void					draw_right(t_fdf size, t_bio *bio, t_values **values);
void					draw_down(t_fdf size, t_bio *bio, t_values **values);
void					slope_slow(t_bio *bio, t_values *values);
void					slope_fast(t_bio *bio, t_values *values);
void					slope_flat(t_bio *bio);

void					rotation(t_bio *bio, t_fdf size);
void					x_rot(t_bio **bio, t_fdf size);
void					y_rot(t_bio **bio, t_fdf size);
void					z_rot(t_bio **bio, t_fdf size);
#endif
