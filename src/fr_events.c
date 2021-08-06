/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:40:39 by esormune          #+#    #+#             */
/*   Updated: 2021/04/19 19:01:17 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Raises or lowers the amount of max iterations.
*/

void	event_iterations(int key, t_img *img)
{
	if (key == (int)'i')
	{
		if (img->max_count >= 250)
			img->max_count -= 10;
		else if (img->max_count >= 50)
			img->max_count -= 5;
		else
			img->max_count -= 1;
	}
	else
	{
		if (img->max_count >= 250)
			img->max_count += 10;
		else if (img->max_count >= 50)
			img->max_count += 5;
		else
			img->max_count += 1;
	}
}

/*
** Cycles through different colour modes.
*/

void	event_mode(t_img *img)
{
	img->mode++;
	if (img->mode > 3)
		img->mode = 0;
	if (img->mode == 0)
		img->bg = BLUE;
	else if (img->mode == 1)
		img->bg = 0X00031D;
	else if (img->mode == 2)
		img->bg = 0XFAECDA;
	else if (img->mode == 3)
		img->bg = 0X7D2803;
}

/*
** Shifts position of origo on screen.
*/

void	event_move_arrow(int key, t_img *img)
{
	float	off;

	off = 10 * img->x_scale * img->zoom;
	if (key == 65361)
		img->x_offset += off;
	else if (key == 65362)
		img->y_offset += off;
	else if (key == 65363)
		img->x_offset -= off;
	else if (key == 65364)
		img->y_offset -= off;
}

/*
** Enacts events for key presses.
*/

int		event_keys(int key, t_img *img)
{
	if (key == 65307)
		fr_exit(img);
	else if (key == 65361 || key == 65362 || key == 65363 || key == 65364)
		event_move_arrow(key, img);
	else if (key == 114)
		fr_reset(img);
	else if (key == (int)'z')
		event_zoom(img->mouse.last_x, img->mouse.last_y, img, 0.999);
	else if (key == (int)'x')
		event_zoom(img->mouse.last_x, img->mouse.last_y, img, 1.001);
	else if (key == (int)'m')
		event_mode(img);
	else if (key == (int)'i' || key == (int)'o')
		event_iterations(key, img);
	img->draw = 0;
	return (0);
}

/*
** Zooms into the fractol based on mouse pointer. First calculates the points
** of x and y with the current zoom, then multiplies that zoom with the given
** value of zoom and checks the new position of the x & y coordinates.
** Afterwards it calculates the offset this new zoom has given the coordinate
** so when the zoom is used, this can be taken into account and the placement
** of the zoomed point on the screen does not change.
*/

void	event_zoom(int x, int y, t_img *img, float zoom)
{
	float	pre_zoom_x;
	float	pre_zoom_y;
	float	zoomed_x;
	float	zoomed_y;

	pre_zoom_x = (float)x * img->zoom;
	pre_zoom_y = (float)y * img->zoom;
	img->zoom *= zoom;
	if (img->mode != 0 && img->zoom < 0.0001)
		img->max_count += 1;
	zoomed_x = (float)x * img->zoom;
	zoomed_y = (float)y * img->zoom;
	img->x_offset += (pre_zoom_x - zoomed_x) * img->x_scale;
	img->y_offset += (pre_zoom_y - zoomed_y) * img->y_scale;
}
