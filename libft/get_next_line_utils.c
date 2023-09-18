/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:43:06 by inunez-g          #+#    #+#             */
/*   Updated: 2022/02/03 12:04:54 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && (unsigned char)c != s[i])
		i++;
	if ((unsigned char)c == s[i])
		return ((char *)&s[i]);
	return (0);
}

char	*ft_substr_gnl(char const *s, int start, int len)
{
	char	*final_str;
	int		i;
	int		j;
	int		reallen;
	int		ft;

	i = start;
	j = 0;
	if (!s || !len)
		return (0);
	if (ft_strlen_gnl(s) < (start + len))
		reallen = (ft_strlen_gnl(s) - start);
	else
		reallen = len;
	if (ft_strlen_gnl(s) < start)
		reallen = 0;
	final_str = (char *)malloc((reallen + 1) * (sizeof(char)));
	if (!final_str)
		return (0);
	ft = ft_strlen_gnl(s);
	while (i < ft && j < reallen)
		final_str[j++] = s[i++];
	final_str[j] = '\0';
	return (final_str);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*final_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	final_str = (char *)malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	i = 0;
	j = 0;
	if (!final_str)
		return (0);
	while (s1[i] != '\0')
		final_str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
	{
		final_str[j] = s2[i];
		j++;
		i++;
	}
	final_str[j] = '\0';
	return (final_str);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(ft_strlen_gnl(s1) + 1);
	if (!(s2))
		return (0);
	ft_memcpy_gnl(s2, s1, ft_strlen_gnl(s1) + 1);
	return (s2);
}
