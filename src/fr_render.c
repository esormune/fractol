/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:44:05 by esormune          #+#    #+#             */
/*   Updated: 2021/04/22 15:32:22 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Calculates whether or not point x, y is a part of the given fractal,
** then sets the colour. Colours the pixel black if it is
** part of the fractol set. If it isn't, it is coloured according
** to its stability, aka how many iterations it takes for the
** point to be "lost".
*/

void	render_fractal(int x, int y, int pixel, t_img *img)
{
	t_complex	c;
	int			count;

	c.x = (x * img->x_scale * img->zoom) + img->x_offset;
	c.y = (y * img->y_scale * img->zoom) + img->y_offset;
	count = img->f(c, img);
	img->win->img[pixel] = draw_colour(count, img);
}

/*
** Divides the image into sections for each thread to work on. Takes
** in a void pointer that is immediately cast into a t_thread. This
** calls the function that calculates the fractals, but only for the
** small bit of screen that has been divided for the particular thread.
*/

void	*render_thread(void *ptr)
{
	t_thread	*t;
	int			y_max;
	int			x;
	int			y;
	int			pixel;

	t = (t_thread *)ptr;
	y = WIN_Y / THREADS * t->id;
	y_max = WIN_Y / THREADS * (t->id + 1);
	pixel = WIN_X * y;
	while (y < y_max)
	{
		x = 0;
		while (x < WIN_X)
		{
			render_fractal(x, y, pixel, t->img);
			pixel++;
			x++;
		}
		y++;
	}
	return (NULL);
}

/*
** If there is an error in creating the threads (pthread returns < 0),
** this function releases all previous threads to avoid leaks and then
** exits the programme.
*/

void	render_release(t_img *img)
{
	int	i;

	i = 0;
	while (i < THREADS && img->render.threads[i] != NULL)
	{
		free(img->render.threads[i]);
		i++;
	}
	ft_putendl("Threading error.");
	fr_exit(img);
}

/*
** Creates the t_render the img pointer points to with the threads for
** multithreading. Gets thread count from .h file and sets each up with
** and id number and a pointer to the img for them to use. Sets every
** thread to work through the render_thread function, and lastly
** joins the threads together.
*/

void	render_img(t_img *img)
{
	int			i;
	t_render	*r;

	i = 0;
	r = &img->render;
	while (i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].img = img;
		if (pthread_create(&(r->threads[i]), NULL,
			render_thread, &(r->args[i])) < 0)
			return (render_release(img));
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(r->threads[i], NULL);
		i++;
	}
	img->draw = 1;
}
