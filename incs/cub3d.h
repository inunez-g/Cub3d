/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:23:03 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/17 12:23:04 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define INVALID_EXTENSION	1
# define INVALID_FILE		2

# include <stdio.h>
# include "colors.h"

/* STRUCTURES */
typedef struct	s_str
{
	char			c;
	struct s_str	*next;
	struct s_str	*prev;
}	t_str;

typedef struct	s_map
{
	t_str	*str;
	t_str	*tmp;
	char	c;
	int		fd;
	char	*tmp_map;
}	t_map;

/* ERROR FUNCTIONS */
void	process_error( int type );

/* FREE FUNCTIONS */

/* GET MAP FUNCTIONS */
void	get_map( char *file, t_map *map_utils );

/* STRING FUNCTIONS */
size_t	ft_strlen( const char *str );
char	*ft_strrchr( const char *str , int c );
int		ft_strcmp( const char *str1, const char *str2 );


#endif
