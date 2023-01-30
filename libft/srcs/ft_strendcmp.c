/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:52:50 by tberube-          #+#    #+#             */
/*   Updated: 2023/01/10 15:10:19 by tberube-         ###   ########.fr       */
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
