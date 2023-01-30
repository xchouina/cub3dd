/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:45:22 by tberube-          #+#    #+#             */
/*   Updated: 2022/03/04 10:02:24 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*end_line(char *all_line, char **save)
{
	char	*tmp;

	free (*save);
	*save = ft_substr_gnl(all_line, l_cnt(all_line, '\n'), \
	ft_strlen_gnl(all_line) - l_cnt(all_line, '\n'));
	if (ft_strchr_gnl(all_line, '\n'))
	{
		tmp = ft_substr_gnl(all_line, 0, l_cnt(all_line, '\n'));
		free(all_line);
		return (tmp);
	}
	else
		return (all_line);
	return (NULL);
}

void	free_pointer(char **str, char **str2)
{
	if (ft_strlen_gnl(*str) > 0)
		*str2 = ft_strjoin_gnl(*str, "");
	free(*str);
	*str = NULL;
}

int	l_cnt(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i + 1);
}

char	*read_line(int fd, char *all_line, int *bytes_read)
{
	char	*tmp;
	char	tampax[BUFFER_SIZE + 1];

	(*bytes_read) = read(fd, tampax, BUFFER_SIZE);
	tampax[*bytes_read] = '\0';
	if (*bytes_read == 0)
	{
		if (all_line)
			return (all_line);
		return (NULL);
	}
	if (!all_line)
	{
		all_line = ft_substr_gnl(tampax, 0, ft_strlen_gnl(tampax));
		return (all_line);
	}
	tmp = all_line;
	all_line = ft_strjoin_gnl(all_line, tampax);
	free(tmp);
	return (all_line);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*all_line;
	int			bytes_read;

	all_line = NULL;
	if (fd == -1 || fd >= 1000 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (ft_strlen_gnl(save) > 0)
		free_pointer(&save, &all_line);
	while (!all_line || !ft_strchr_gnl(all_line, '\n'))
	{
		all_line = read_line(fd, all_line, &bytes_read);
		if (bytes_read == 0)
		{
			free_pointer(&save, &all_line);
			if (all_line)
				return (all_line);
			return (NULL);
		}
		if (bytes_read < BUFFER_SIZE)
			break ;
	}
	if (ft_strchr_gnl(all_line, '\n'))
		return (end_line(all_line, &save));
	return (all_line);
}
