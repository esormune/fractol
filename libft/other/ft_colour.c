/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:43:28 by esormune          #+#    #+#             */
/*   Updated: 2021/03/16 14:44:19 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_colour(int r, int g, int b)
{
	return ((r * 65536) + (g * 256) + b);
}
