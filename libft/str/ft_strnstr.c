/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:10:28 by esormune          #+#    #+#             */
/*   Updated: 2021/03/25 23:49:32 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		x;
	char	*hs;

	i = 0;
	x = 0;
	hs = (char*)haystack;
	if (needle[x] == '\0')
		return (hs);
	while (hs[i] != '\0' && i < len)
	{
		x = 0;
		while (hs[i + x] == needle[x] && hs[i + x] != '\0'
			&& (i + x) != len)
		{
			if (needle[x + 1] == '\0')
				return (&hs[i]);
			x++;
		}
		i++;
	}
	return (NULL);
}
