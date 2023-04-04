/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:52:02 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/04 10:20:25 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	t;
	unsigned char	*str;

	str = (unsigned char *) s;
	t = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (*str == t)
			return (str);
		i++;
		str++;
	}
	return (NULL);
}
