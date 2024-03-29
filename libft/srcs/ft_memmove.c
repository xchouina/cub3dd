/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:04:12 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/04 10:20:20 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dest == src || !len)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = -1;
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
	{
		while (++i < len)
			d[i] = s[i];
	}
	return (dest);
}
