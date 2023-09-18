/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:55:13 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/18 01:08:46 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"
#include <errno.h>

static void	print_usage( void )
{
	printf(YELLOW "Usage: ./cub3d <file_name>.cub\n" RESET);
}

static void	print_error( char  *error, void (*f)(void))
{
	printf(RED "%s\n" RESET, error);
	if (f)
		(*f)();
}

/*
 * Handles different types of errors and takes appropiate actions.
 * Parameters:
 *     type: the error code to be processed
 */
void	process_error( int type )
{
	if (type == INVALID_EXTENSION)
		print_error("cub3d: error: invalid extension", print_usage);
	if (type == INVALID_FILE)
		print_error("cub3d: error: invalid file", NULL);
	if (type == INVALID_TEXTURE)
		print_error("cub3d: error: invalid texture", NULL);
}
