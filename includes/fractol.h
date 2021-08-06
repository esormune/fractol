/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:50:24 by esormune          #+#    #+#             */
/*   Updated: 2021/04/20 17:03:39 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# define WIN_X 800
# define WIN_Y 800
# define WIN_MAX 640000
# define THREADS 8
# define WHITE 0XFFFFFF
# define BLACK 0X000000
# define BLUE 0X0000FF

typedef struct s_img		t_img;
typedef struct s_complex	t_complex;

typedef struct				s_win
{
	void					*mlx_ptr;
	void					*win_ptr;
	void					*img_ptr;
	int						*img;
	int						endian;
	int						size_line;
	int						bpp;
}							t_win;

typedef struct				s_mouse
{
	int						is_down;
	int						last_x;
	int						last_y;
	int						new_x;
	int						new_y;
}							t_mouse;

typedef struct				s_thread
{
	int						id;
	t_img					*img;
}							t_thread;

typedef struct				s_render
{
	pthread_t				threads[THREADS];
	t_thread				args[THREADS];
}							t_render;

struct						s_img
{
	t_win					*win;
	t_mouse					mouse;
	t_render				render;
	int						(*f)(t_complex, void *);
	int						fractol;
	float					x_max;
	float					y_max;
	float					x_min;
	float					y_min;
	float					x_dist;
	float					y_dist;
	float					x_scale;
	float					y_scale;
	float					origo_x;
	float					origo_y;
	float					x_offset;
	float					y_offset;
	int						draw;
	long double				zoom;
	int						mode;
	int						bg;
	int						max_count;
};

int							die(char *reason);
int							die_usage(void);
void						fr_reset(t_img *img);
int							fr_exit(t_img *img);
int							fr_init(t_img *img, t_win *win);
void						fr_valid(char *str, t_img *img);
int							draw_img(t_img *img);
int							draw_colour(int count, t_img *img);
void						render_img(t_img *img);
int							event_keys(int key, t_img *img);
void						event_zoom(int x, int y, t_img *img, float zoom);
int							mouse_down(int button, int x, int y, t_img *img);
int							mouse_up(int button, int x, int y, t_img *img);
int							mouse_move(int x, int y, t_img *img);
int							fr_mandelbrot(t_complex c, t_img *img);
int							fr_julia(t_complex c, t_img *img);
int							fr_burningship(t_complex c, t_img *img);
int							fr_orb(t_complex c, t_img *img);
int							fr_spirals(t_complex c, t_img *img);
int							fr_splat(t_complex c, t_img *img);
int							fr_static(t_complex c, t_img *img);
int							fr_sun(t_complex c, t_img *img);
int							fr_mosaic(t_complex c, t_img *img);
int							fr_mitosis(t_complex c, t_img *img);
void						text_put(t_img *img);

#endif
