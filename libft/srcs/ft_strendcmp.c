/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:52:50 by tberube-          #+#    #+#             */
/*   Updated: 2023/04/04 10:18:25 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>

int	ft_strendcmp(const char *s, const char *suffix)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (!s || !suffix)
		return (0);
	i = (ft_strlen(s) - ft_strlen(suffix));
	while (s[i])
	{
		if (s[i] != suffix[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}
