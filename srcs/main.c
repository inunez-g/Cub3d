/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:35:57 by inunez-g          #+#    #+#             */
/*   Updated: 2023/09/18 11:35:57 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"


int	main(int argc, char **argv)
{
	t_map	map_utils;

	if (argc == 2)
	{
		if (!get_map(argv[1], &map_utils))
		{
			//seguimos programa
			printf("Bien");
			return(0);
		}
		else
		{
			printf("Mal");
			return (-1);
		}
	}
}
