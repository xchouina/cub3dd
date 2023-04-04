/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:34:26 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/04 10:21:58 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// NOTE: 	"ft_arrayadd" adds an allocated str (2nd param.) 
// NOTE:	 at the end of a double array (1st param.).

char	**ft_arrayadd(char **tab, char *str_to_add)
{
	char	**new;
	int		i;

	if (str_to_add == NULL)
		return (tab);
	new = malloc(sizeof(char *) * (ft_arraylen(tab) + 2));
	i = 0;
	while (tab && tab[i])
	{
		new[i] = tab[i];
		i++;
	}
	new[i++] = str_to_add;
	new[i] = NULL;
	if (tab)
		free(tab);
	return (new);
}
