/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:07:57 by inunez-g          #+#    #+#             */
/*   Updated: 2023/12/04 15:25:05 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*
 * Checks if a character is a white space character.
 * Parameters:
 *     c: the character to check
 * Return:
 *     1: if 'c' is a white space  character
 *     0: if it is not.
 */
int	ft_isspace( int c )
{
	return ((c >= 9 && c <= 13) || c == 32);
}

/*
 * Check is a character is a digit.
 * Parameters:
 *     c: the character to check
 * Return:
 *     1: if 'c' is a digit
 *     0: if it is not.
 */
int	ft_isdigit( int c )
{
	return (c >= 48 && c <= 57);
}

int	ft_strdigit( char *str )
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (!str[i]);
}
