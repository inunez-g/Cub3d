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
# define INVALID_TEXTURE	3
# define TEXTURES 			"NO EA WE SO C F"

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

typedef struct	s_textures
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*c;
	char	*f;
	int		filled;
}	t_textures;

/* CHECK FUNCTIONS */
int ft_isspace(int c);

/* ERROR FUNCTIONS */
void	process_error( int type );

/* FREE FUNCTIONS */

/* GET MAP FUNCTIONS */
int	get_map( char *file, t_map *map_utils );//Era void pero asi pinta bien

/* STRING FUNCTIONS */
size_t	ft_strlen( const char *str );
char	*ft_strrchr( const char *str , int c );
int		ft_strcmp( const char *str1, const char *str2 );

/* HELPFUL FUNCTIONS */
void	pass_spaces(char *str, int *i);

#endif
