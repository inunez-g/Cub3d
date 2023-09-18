/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:44:04 by inunez-g          #+#    #+#             */
/*   Updated: 2021/11/18 11:40:47 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_writeerror(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

int	ft_atoi(const char *str)
{
	unsigned int		i;
	int					j;
	unsigned long int	nb;

	i = 0;
	j = 1;
	nb = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			j = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	if ((str[i] <= 47 || str[i] >= 58) && str[i] != '\0')
		ft_writeerror();
	if (nb > 2147483648 && j == -1)
		ft_writeerror();
	if (nb > 2147483647 && j == 1)
		ft_writeerror();
	return (nb * j);
}
