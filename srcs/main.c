/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:22:43 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/18 01:09:10 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"


int	main(int argc, char **argv)
{
	t_map	map_utils;

	if (argc == 2)
	{
		get_map(argv[1], &map_utils);
	}
}
