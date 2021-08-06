/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:16:22 by esormune          #+#    #+#             */
/*   Updated: 2021/04/08 17:07:21 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Destorys image and exits programme.
*/

int	fr_exit(t_img *img)
{
	mlx_destroy_image(img->win->mlx_ptr, img->win->img_ptr);
	exit(0);
}

/*
** Allocates memory for the window struct. Initialises mlx window.
** Contains the function that loops and calls draw image.
*/

int	fr_init(t_img *img, t_win *win)
{
	if (!(win->mlx_ptr = mlx_init()))
		return (die("Error opening window."));
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_X, WIN_Y, "Fractol");
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIN_X, WIN_Y);
	win->img = NULL;
	win->img = (int *)mlx_get_data_addr(win->img_ptr, &win->bpp,
		&win->size_line, &win->endian);
	win->size_line /= 4;
	mlx_hook(win->win_ptr, 33, 0, fr_exit, img);
	mlx_hook(win->win_ptr, 2, (long)1L, event_keys, img);
	mlx_hook(win->win_ptr, 4, 1L << 2, mouse_down, img);
	mlx_hook(win->win_ptr, 5, 1L << 3, mouse_up, img);
	mlx_hook(win->win_ptr, 6, 1L << 6, mouse_move, img);
	mlx_loop_hook(win->mlx_ptr, draw_img, img);
	mlx_loop(win->mlx_ptr);
	return (0);
}
