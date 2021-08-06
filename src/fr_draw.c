/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:38:36 by esormune          #+#    #+#             */
/*   Updated: 2021/04/27 13:58:19 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Resets image to specified colour.
*/

void		reset_img(t_win *win, int colour)
{
	size_t	i;

	i = 0;
	while (i < WIN_MAX)
	{
		win->img[i] = colour;
		i++;
	}
}

/*
** Returns the colour of the pixel for gradient view.
*/

static int	draw_gradient(int count, t_img *img)
{
	int		rg;
	double	percent;

	if (count == img->max_count)
		return (BLACK);
	else if (count < 2)
		return (BLUE);
	else
	{
		percent = (float)count / (float)img->max_count;
		rg = (int)(255 * percent);
		return (ft_colour(rg, rg, 255));
	}
}

/*
** Returns a colour based on the iteration loop. If max iteration,
** returns black. Four modes: blue-white gradient, ultra, pastel, or burning.
*/

int			draw_colour(int count, t_img *img)
{
	static int	u_colours[16] = {0X421E0F, 0X19071A, 0X09012F, 0X040449,
		0X000764, 0X0C2C8A, 0X1852B1, 0X397DD1, 0X86B5E5, 0XD3ECF8, 0XF1E9BF,
		0XF8C95F, 0XFFAA00, 0XCC8000, 0X995700, 0X6A3403};
	static int	p_colours[10] = {WHITE, 0XFFD2D2, 0XFFAFAF, 0XF4A8FF, 0XA8E3FF,
		0XA8FAFF, 0XA8FFC2, 0XC2FFA8, 0XFFFFA8, 0XFFDAA8};
	static int	b_colours[16] = {0X4E1600, 0X922B00, 0XAB4100, 0XC05500,
		0XD77600, 0XE69000, 0XF5BA00, 0XFACE00, 0XFCDF00, 0XFEEE00, 0XE89A00,
		0XC15B00, 0X9E4100, 0X662B00, 0X501900, 0X5A3500};

	if (count == img->max_count)
		return (BLACK);
	else if (count < 2)
		return (img->bg);
	else if (img->mode == 1)
		return (u_colours[count % 16]);
	else if (img->mode == 2)
		return (p_colours[count % 10]);
	else if (img->mode == 3)
		return (b_colours[count % 16]);
	else
		return (draw_gradient(count, img));
}

/*
** Draws the fractol image if draw variable is not set, aka if image is not
** already drawn.
*/

int			draw_img(t_img *img)
{
	if (img->draw == 0)
	{
		reset_img(img->win, BLUE);
		render_img(img);
	}
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr,
		img->win->img_ptr, 0, 0);
	text_put(img);
	return (0);
}
