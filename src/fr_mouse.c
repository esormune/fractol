/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:19:52 by esormune          #+#    #+#             */
/*   Updated: 2021/04/20 15:42:36 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Deals with a mouse button being used, either to zoom
** or to move image.
*/

int	mouse_down(int button, int x, int y, t_img *img)
{
	if (button == 5)
		event_zoom(x, y, img, 1.001);
	else if (button == 4)
		event_zoom(x, y, img, 0.999);
	else if (button == 1)
	{
		img->mouse.is_down = 1;
		img->mouse.last_x = x;
		img->mouse.last_y = y;
		return (0);
	}
	img->draw = 0;
	return (0);
}

/*
** Deals with mouse movement. Captures the x and y and uses for click and drag
** or zoom.
*/

int	mouse_move(int x, int y, t_img *img)
{
	if (img->mouse.is_down)
	{
		img->x_offset -= ((x - img->mouse.last_x) * img->x_scale * img->zoom);
		img->y_offset -= ((y - img->mouse.last_y) * img->y_scale * img->zoom);
		img->mouse.last_x = x;
		img->mouse.last_y = y;
		img->draw = 0;
	}
	else
	{
		img->mouse.last_x = x;
		img->mouse.last_y = y;
		if (img->fractol == 2 || (img->fractol >= 6 && img->fractol <= 10))
			img->draw = 0;
	}
	return (0);
}

/*
** Checks if mouse has been released to stop click and drag.
*/

int	mouse_up(int button, int x, int y, t_img *img)
{
	(void)x;
	(void)y;
	(void)button;
	img->mouse.is_down = 0;
	return (0);
}
