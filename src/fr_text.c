/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:49:35 by esormune          #+#    #+#             */
/*   Updated: 2021/04/20 17:01:26 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Returns a colour for the text.
*/

static int	text_get_colour(t_img *img)
{
	if (img->mode == 2)
		return (BLACK);
	else
		return (WHITE);
}

/*
** Places the HUD text on the window.
*/

void		text_put(t_img *img)
{
	char	*str;
	int		colour;

	colour = text_get_colour(img);
	if (!(str = ft_calloc(100, sizeof(char))))
		return (ft_putendl("Malloc failure."));
	ft_sprintf(str, "Iterations: %d", img->max_count);
	mlx_string_put(img->win->mlx_ptr, img->win->win_ptr, 50, 50, colour,
		str);
	ft_sprintf(str, "Zoom: %Lf", img->zoom);
	mlx_string_put(img->win->mlx_ptr, img->win->win_ptr, 50, 65, colour,
		str);
	mlx_string_put(img->win->mlx_ptr, img->win->win_ptr, 50, 80, colour,
		"Remove / add iterations: I / O");
	mlx_string_put(img->win->mlx_ptr, img->win->win_ptr, 50, 95, colour,
		"Change mode: M");
	mlx_string_put(img->win->mlx_ptr, img->win->win_ptr, 50, 110, colour,
		"Zoom: Z / X");
	mlx_string_put(img->win->mlx_ptr, img->win->win_ptr, 50, 125, colour,
		"Reset: R");
	free(str);
}
