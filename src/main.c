/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:49:39 by esormune          #+#    #+#             */
/*   Updated: 2021/04/20 15:49:15 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	die_usage(void)
{
	ft_putendl("Usage: ./fractol fractal");
	ft_putendl("\tAvailable fractals:");
	ft_putendl("\t- Mandelbrot");
	ft_putendl("\t- Julia");
	ft_putendl("\t- Burningship");
	ft_putendl("\t- Orb");
	ft_putendl("\t- Spirals");
	ft_putendl("\t- Splat");
	ft_putendl("\t- Static");
	ft_putendl("\t- Sun");
	ft_putendl("\t- Mosaic");
	ft_putendl("\t- Mitosis");
	return (0);
}

int	die(char *reason)
{
	ft_putendl(reason);
	return (0);
}

int	main(int argc, char **argv)
{
	t_img	*img;

	if (argc != 2)
		return (die_usage());
	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (die("Malloc error."));
	if (!(img->win = (t_win *)malloc(sizeof(t_win))))
		return (die("Malloc error."));
	img->f = NULL;
	fr_valid(argv[1], img);
	if (!(img->f))
		return (die_usage());
	fr_reset(img);
	fr_init(img, img->win);
	return (0);
}
