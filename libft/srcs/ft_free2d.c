/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42quebec.com   	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:21:40 by mjarry          #+#    #+#           	  */
/*   Updated: 2022/10/10 13:21:40 by mjarry         ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_free2d(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
