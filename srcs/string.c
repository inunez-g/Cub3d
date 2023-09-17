/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:37:11 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/18 01:08:53 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*
 * Calculates the length of a string excluding the null terminator character.
 * Parameters:
 *     str: pointer to the string in which the length will be calculated
 * Return:
 *     i: the length of the string
 */
size_t	ft_strlen( const char *str )
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

/*
 * Searches for the last ocurrence of the character 'c' in the string pointed
 * to by 'str'.
 * Parameters:
 *     str: pointer to the string in which the search will be performed
 *     c: the character to search for in the string
 * Return:
 *     A pointer to the last found character
 *     NULL if the character is not found
 */
char	*ft_strrchr( const char *str , int c )
{
	size_t	i;

	i = ft_strlen(str);
	while (i--)
	{
		if (*(str + i) == (char)c)
			return ((char *)str + i);
	}
	return (NULL);
}

/*
 * Compares two strings.
 * Parameters:
 *     str1: pointer to the first string for comparison
 *     str2: pointer to the second string for comparison
 * Return:
 *     0 is tr1 is equal to str2
 *     A negative value if str1 is less than str2
 *     A positive value is str1 is greater than str2
 */
int	ft_strcmp( const char *str1, const char *str2 )
{
	if (!str1 || !str2)
		return (0);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
