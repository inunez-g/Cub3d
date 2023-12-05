/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:08:08 by inunez-g          #+#    #+#             */
/*   Updated: 2023/12/05 11:23:37 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*
 * 
 */
int	main( int argc, char **argv )
{
	t_game	game;

	if (argc == 2)
	{
		init(&game);
		get_map(argv[1], &game);
		get_textures(&game);
		process_game(&game);
		return (1);
	}
	printf(RED "cub3d: error: invalid paramater\n" RESET);
	printf(YELLOW "Usage: ./cub3d <file_name>.cub\n" RESET);
	return (0);
}
