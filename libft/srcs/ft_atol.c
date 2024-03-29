/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:11:53 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/04 10:21:31 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

long	ft_atol(const char *str)
{
	unsigned long	neg;
	unsigned long	res;

	res = 0;
	neg = 1;
	while (((*str >= 9 && *str <= 13) || (*str == 32)) && (*str))
		str++;
	if ((*str == '+' || *str == '-') && (*str))
	{
		if (*str == '-')
			neg *= (-1);
		str++;
	}
	while ((*str >= '0' && *str <= '9') && (*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * neg);
}
