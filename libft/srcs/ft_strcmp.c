/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:04:05 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/04 10:18:33 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (((s1[i] > '\0') && (s1[i] == s2[i])))
		i++;
	return (((unsigned char) s1[i]) - ((unsigned char) s2[i]));
}
