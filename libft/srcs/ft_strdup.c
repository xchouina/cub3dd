/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:16:06 by xchouina          #+#    #+#             */
/*   Updated: 2023/04/04 10:18:27 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(char *s1)
{
	int		l;
	char	*dup;

	l = ft_strlen(s1);
	dup = ft_calloc((l + 1), sizeof(char));
	if (!dup)
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
