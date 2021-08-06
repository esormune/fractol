/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:31:12 by esormune          #+#    #+#             */
/*   Updated: 2021/04/19 18:54:07 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Initialises the mouse struct.
*/

static void	reset_mouse(t_mouse *mouse)
{
	mouse->is_down = 0;
	mouse->last_x = 0;
	mouse->last_y = 0;
	mouse->new_x = 0;
	mouse->new_y = 0;
}

/*
** Sets the background based on mode.
*/

static void	reset_bg(t_img *img)
{
	if (img->mode == 0)
		img->bg = BLUE;
	if (img->mode == 1)
		img->bg = 0X00031D;
	if (img->mode == 2)
		img->bg = 0XFAECDA;
	if (img->mode == 3)
		img->bg = 0X7D2803;
}

/*
** Sets the default modesfor each fractal if they deviate from the mode 0.
*/

static void	reset_mode(t_img *img)
{
	if (img->fractol == 3)
		img->mode = 3;
	else if (img->fractol == 4)
		img->mode = 1;
	else if (img->fractol == 6)
		img->mode = 2;
	else if (img->fractol == 7)
		img->mode = 1;
	else if (img->fractol == 8)
		img->mode = 1;
	else if (img->fractol == 9)
		img->mode = 1;
	else if (img->fractol == 10)
		img->mode = 2;
}

/*
** Sets the default iterations for each fractal if they deviate from 50.
*/

static void	reset_iterations(t_img *img)
{
	if (img->fractol == 3)
		img->max_count = 64;
	else if (img->fractol == 4)
		img->max_count = 35;
	else if (img->fractol == 5)
		img->max_count = 400;
	else if (img->fractol == 6)
		img->max_count = 135;
	else if (img->fractol == 8)
		img->max_count = 27;
	else if (img->fractol == 10)
		img->max_count = 10;
}

/*
** Initialises and/or resets the img struct to its original values.
*/

void		fr_reset(t_img *img)
{
	img->x_max = 2.0;
	img->y_max = 2.0;
	img->x_min = -2.0;
	img->y_min = -2.0;
	img->x_offset = -2.0;
	img->y_offset = -2.0;
	img->x_dist = img->x_max - img->x_min;
	img->y_dist = img->y_max - img->y_min;
	img->x_scale = img->x_dist / WIN_X;
	img->y_scale = img->y_dist / WIN_Y;
	img->origo_x = WIN_X / 2;
	img->origo_y = WIN_Y / 2;
	img->draw = 0;
	img->max_count = 50;
	img->zoom = 1.0;
	img->mode = 0;
	img->bg = BLUE;
	reset_mouse(&img->mouse);
	reset_mode(img);
	reset_iterations(img);
	reset_bg(img);
}
