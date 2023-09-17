/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:22:49 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/18 01:09:01 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"
#include <fcntl.h>

/*
 * Checks if the given file has a specified extension incluiding the dot.
 * If either pointer is NULL, of ir they are not equal, exits the program with
 * an INVALID_EXTENSION code.
 * Parameters:
 *     file: pointer to the file name to be checked
 *     extension: pointer to he expected file extension
 */
void	check_extension( char *file, char *extension )
{
	char	*file_extension;

	if (!file || !extension)
		process_error(INVALID_EXTENSION);
	file_extension = ft_strrchr(file, '.');
	if (ft_strcmp(extension, file_extension))
		process_error(INVALID_EXTENSION);
}


void	get_map( char *file, t_map *map_utils )
{
	check_extension(file, ".cub");
	map_utils->fd = open(file, O_RDONLY);
	if (map_utils->fd == -1)
		process_error(INVALID_FILE);
}
