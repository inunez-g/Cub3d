/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:43:39 by inunez-g          #+#    #+#             */
/*   Updated: 2022/02/03 12:03:14 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char const *s, int start, int len);
int		ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_save_line(char *temp);
char	*ft_update_temp(char *temp);
char	*ft_strdup_gnl(const char *s1);
void	*ft_memcpy_gnl(void *dst, const void *src, size_t n);
char	*ft_save_temp(char *temp, char *buffer);

#endif
