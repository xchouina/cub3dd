/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:06:21 by xchouina          #+#    #+#             */
/*   Updated: 2022/07/12 12:07:36 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isquote(const int c)
{
	if (c == 34)
		return (2);
	else if (c == 39)
		return (1);
	else
		return (0);
}
