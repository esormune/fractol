/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:08:26 by esormune          #+#    #+#             */
/*   Updated: 2021/04/20 15:36:19 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Sets the img->f to the fractal's function.
*/

static void	set_function(t_img *img)
{
	if (img->fractol == 1)
		img->f = (void *)&fr_mandelbrot;
	else if (img->fractol == 2)
		img->f = (void *)&fr_julia;
	else if (img->fractol == 3)
		img->f = (void *)&fr_burningship;
	else if (img->fractol == 4)
		img->f = (void *)&fr_orb;
	else if (img->fractol == 5)
		img->f = (void *)&fr_spirals;
	else if (img->fractol == 6)
		img->f = (void *)&fr_splat;
	else if (img->fractol == 7)
		img->f = (void *)&fr_static;
	else if (img->fractol == 8)
		img->f = (void *)&fr_sun;
	else if (img->fractol == 9)
		img->f = (void *)&fr_mosaic;
	else if (img->fractol == 10)
		img->f = (void *)&fr_mitosis;
}

/*
** Checks the validity of argument given; if it matches with available
** fractols.
*/

void		fr_valid(char *str, t_img *img)
{
	ft_tolower_str(str);
	if (ft_strcmp(str, "mandelbrot") == 0)
		img->fractol = 1;
	else if (ft_strcmp(str, "julia") == 0)
		img->fractol = 2;
	else if (ft_strcmp(str, "burningship") == 0)
		img->fractol = 3;
	else if (ft_strcmp(str, "orb") == 0)
		img->fractol = 4;
	else if (ft_strcmp(str, "spirals") == 0)
		img->fractol = 5;
	else if (ft_strcmp(str, "splat") == 0)
		img->fractol = 6;
	else if (ft_strcmp(str, "static") == 0)
		img->fractol = 7;
	else if (ft_strcmp(str, "sun") == 0)
		img->fractol = 8;
	else if (ft_strcmp(str, "mosaic") == 0)
		img->fractol = 9;
	else if (ft_strcmp(str, "mitosis") == 0)
		img->fractol = 10;
	else
		img->fractol = 0;
	if (img->fractol != 0)
		set_function(img);
}
