/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:59:27 by tberube-          #+#    #+#             */
/*   Updated: 2022/03/04 10:03:28 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (len > ft_strlen_gnl(s))
		len = ft_strlen_gnl(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy_gnl(str, s + start, len + 1);
	return (str);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	dst = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	char		*a_dst;
	const char	*a_src;
	size_t		j;

	a_dst = dst;
	a_src = src;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen_gnl(src));
	while (dstsize > 1 && a_src[j] != '\0')
	{
		a_dst[j] = a_src[j];
		j++;
		dstsize--;
	}
	a_dst[j] = '\0';
	while (a_src[j] != '\0')
		j++;
	return (j);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	while (*s && *s != '\0')
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *) s);
	return (0);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
