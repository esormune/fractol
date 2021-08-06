/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_fractals_cont.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:48:27 by esormune          #+#    #+#             */
/*   Updated: 2021/04/20 15:48:49 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Checks if the complex number c is a part of the dj fractal set.
** The formula is z = (((z^16 / c) / (z^4 + c)^8) + c) * z * c.
** Stops when it reaches max iterations or when the distance from origo
** is greater than 2. Returns the iteration count.
** Takes mouse pointer for c.
*/

int	fr_splat(t_complex c, t_img *img)
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
		z = ft_c_multiply(ft_c_multiply(ft_c_add(ft_c_divide(ft_c_divide(
			ft_c_sq(ft_c_sq(ft_c_sq(ft_c_sq(z)))), c), ft_c_sq(ft_c_sq(
			ft_c_sq(ft_c_add(ft_c_sq(ft_c_sq(z)), z))))), c), z), c);
		count++;
	}
	return (count);
}

/*
** Checks if the complex number c is a part of the static fractal set.
** The formula is z = (((((z^16 / c) * (z^4 + z)^8) + c) / z) * c.
** Stops when it reaches max iterations or when the distance from origo
** is greater than 2. Returns the iteration count.
** Takes mouse pointer for c.
*/

int	fr_static(t_complex c, t_img *img)
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
		z = ft_c_multiply(ft_c_divide(ft_c_add(ft_c_multiply(ft_c_divide(
			ft_c_sq(ft_c_sq(ft_c_sq(ft_c_sq(z)))), c), ft_c_sq(ft_c_sq(
			ft_c_sq(ft_c_add(ft_c_sq(ft_c_sq(z)), z))))), c), z), c);
		count++;
	}
	return (count);
}

/*
** Checks if the complex number c is a part of the sun fractal set.
** The formula is z = (((c^8 / c) / (z^2 + z)^8) + c) * z.
** Stops when it reaches max iterations or when the distance from origo
** is greater than 2. Returns the iteration count.
** Takes mouse pointer for c.
*/

int	fr_sun(t_complex c, t_img *img)
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
		z = ft_c_multiply(ft_c_add(ft_c_divide(ft_c_divide(
			ft_c_sq(ft_c_sq(ft_c_sq(c))), c), ft_c_sq(ft_c_sq(
			ft_c_sq(ft_c_add(ft_c_sq(z), z))))), c), z);
		count++;
	}
	return (count);
}

/*
** Checks if the complex number c is a part of the mosaic fractal set.
** The formula is z = (((c^8 / c) / (z^2 + z^2)^8) + c) * z.
** Stops when it reaches max iterations or when the distance from origo
** is greater than 2. Returns the iteration count.
** Takes mouse pointer for c.
*/

int	fr_mosaic(t_complex c, t_img *img)
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
		z = ft_c_multiply(ft_c_add(ft_c_divide(ft_c_divide(
			ft_c_sq(ft_c_sq(ft_c_sq(c))), c), ft_c_sq(ft_c_sq(
			ft_c_sq(ft_c_add(ft_c_sq(z), ft_c_sq(z)))))), c), z);
		count++;
	}
	return (count);
}

/*
** Checks if the complex number c is a part of the mitosis fractal set.
** The formula is z = (((z^8 / c) / (z^2 + c^2)^8) / c) * z.
** Stops when it reaches max iterations or when the distance from origo
** is greater than 2. Returns the iteration count.
** Takes mouse pointer for c.
*/

int	fr_mitosis(t_complex c, t_img *img)
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
		z = ft_c_multiply(ft_c_divide(ft_c_divide(ft_c_divide(
			ft_c_sq(ft_c_sq(ft_c_sq(z))), c), ft_c_sq(ft_c_sq(
			ft_c_sq(ft_c_add(ft_c_sq(z), ft_c_sq(c)))))), c), z);
		count++;
	}
	return (count);
}
