/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:07:50 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/04 10:21:44 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// NOTE: "ft_arraylen" counts the length of x (where tab[x][y]).

int	ft_arraylen(char **tab)
{
	int	len;

	len = 0;
	while (tab && tab[len])
		len++;
	return (len);
}
