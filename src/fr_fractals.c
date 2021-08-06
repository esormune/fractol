/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_fractals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:12:06 by esormune          #+#    #+#             */
/*   Updated: 2021/04/20 15:48:52 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Checks if the complex number c is a part of the mandelbrot set.
** The formula is z = z * z + c. Stops when it reaches max iterations or when
** the distance from origo is greater than 2. Returns the iteration count.
*/

int	fr_mandelbrot(t_complex c, t_img *img)
{
	t_complex	z;
	int			count;

	z.x = 0.0;
	z.y = 0.0;
	count = 0;
	while (count < img->max_count && (z.x * z.x + z.y * z.y < 4))
	{
		z = ft_c_add(ft_c_sq(z), c);
		count++;
	}
	return (count);
}

/*
** Checks if the complex number c is a part of the julia set. The formula
** is z = z * z + c, but unlike the mandelbrot set where z begins at zero,
** z is every complex number on the screen and c is the mouse pointer.
** Stops when it reaches max iterations or when the distance from origo is
** greater than 2. Returns the iteration count.
*/

int	fr_julia(t_complex c, t_img *img)
{
	t_complex	z;
	int			count;

	z.x = c.x;
	z.y = c.y;
	c.x = img->mouse.last_x * img->x_scale * img->zoom + img->x_offset;
	c.y = img->mouse.last_y * img->y_scale * img->zoom + img->y_offset;
	count = 0;
	while (count < img->max_count && (z.x * z.x + z.y * z.y < 4))
	{
		z = ft_c_add(ft_c_sq(z), c);
		count++;
	}
	return (count);
}

/*
** Checks if the complex number c is a part of the burning ship set.
** The formula is z = abs(z)^2 + c. Stops when it reaches max iterations
** or when the distance from origo is greater than 2.
** Returns the iteration count.
*/

int	fr_burningship(t_complex c, t_img *img)
{
	t_complex	z;
	int			count;
	float		x_temp;

	z.x = 0.0;
	z.y = 0.0;
	count = 0;
	while (count < img->max_count && (z.x * z.x + z.y * z.y < 4))
	{
		x_temp = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2 * (ft_abs(z.x * z.y)) + c.y;
		z.x = x_temp;
		count++;
	}
	return (count);
}

/*
** Checks if the complex number c is a part of the orb fractal set.
** The formula is z = (((z^16 / c) / (z^4 + c)^8) + c) * z * c.
** Stops when it reaches max iterations or when the distance from origo
** is greater than 2. Returns the iteration count.
*/

int	fr_orb(t_complex c, t_img *img)
{
	t_complex	z;
	int			count;

	z.x = -1.0;
	z.y = -1.0;
	count = 0;
	while (count < img->max_count && (z.x * z.x + z.y * z.y < 4))
	{
		z = ft_c_multiply(ft_c_multiply(ft_c_add(ft_c_divide(ft_c_divide(
			ft_c_sq(ft_c_sq(ft_c_sq(ft_c_sq(z)))), c), ft_c_sq(ft_c_sq(
			ft_c_sq(ft_c_add(ft_c_sq(ft_c_sq(z)), z))))), c), z), c);
		count++;
	}
	return (count);
}

/*
** Checks if the complex number c is a part of the spirals fractal set.
** The formula is z = (c^2 + z^2)^2. C has given points.
** Stops when it reaches max iterations or when the distance
** from origo is greater than 2. Returns the iteration count.
*/

int	fr_spirals(t_complex c, t_img *img)
{
	t_complex	z;
	int			count;

	z.x = c.x;
	z.y = c.y;
	c.x = 0.13499999;
	c.y = 0.869999885;
	count = 0;
	while (count < img->max_count && (z.x * z.x + z.y * z.y < 4))
	{
		z = ft_c_sq(ft_c_add(ft_c_sq(c), ft_c_sq(z)));
		count++;
	}
	return (count);
}
