/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:39:52 by tberube-          #+#    #+#             */
/*   Updated: 2022/03/04 10:02:36 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

#undef BUFFER_SIZE
# define BUFFER_SIZE 1

char	*get_next_line(int const fd);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
void	*ft_memcpy_gnl(void *dst, const void *src, size_t n);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strchr_gnl(const char *s, int c);
void	no_end_line(char **save, char *tampon);
char	*end_fd(char *save, char *tampon, char *tmp);
int		l_cnt(char *str, int c);
char	*gratuit(char *detruis);
int		*line_lenght(char *str, int c);

#endif
