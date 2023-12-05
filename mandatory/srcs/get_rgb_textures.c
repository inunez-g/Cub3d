/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:19:20 by sperez-p          #+#    #+#             */
/*   Updated: 2023/12/05 13:09:26 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*
 *
 */
static int	check_hex(int nbr)
{
	return (nbr >= 0 && nbr <= 255);
}

/*
 *
 */
static unsigned int	rgb_to_hex(int color[3], t_game *game, char **texture)
{
	if (!check_hex(color[0]) || !check_hex(color[1]) || !check_hex(color[2]))
	{
		if (texture)
			free_2dstr(texture);
		process_error(COLOR_ERROR, game);
	}
	return ((1 << 24 | (color[0] & 0xFF) << 16) | ((color[1] & 0xFF) << 8) | \
	(color[2] & 0xFF));
}

/* static int	check_comma( char **str, int i )
{
	
	return (!ft_strcmp(str[i], ",") && str[i + 1])
} */

static void	get_rgb_aux( char **texture, t_game *game, int i)
{
	char	*tmp;

	if (texture[i][0] == ',')
	{
		free_2dstr(texture);
		process_error(COLOR_ERROR, game);
	}
	else if (ft_strchr(texture[i], ','))
	{
		tmp = texture[i];
		texture[i] = ft_strtrim(texture[i], ",");
		free(tmp);
	}
	if (!ft_strdigit(texture[i]))
	{
		free_2dstr(texture);
		process_error(COLOR_ERROR, game);
	}
}

unsigned int	get_rgb_texture_aux( char **texture, t_game *game )
{
	int		i;
	int		j;
	int		color[3];

	i = 0;
	j = 0;
	while (texture[++i])
	{
		if (j > 2)
		{
			free_2dstr(texture);
			process_error(INVALID_TEXTURE, game);
		}
		if (!ft_strcmp(texture[i], ","))
			continue ;
		get_rgb_aux(texture, game, i);
		color[j] = ft_atoi(texture[i]);
		j++;
	}
	return (rgb_to_hex(color, game, texture));
}

unsigned int	get_rgb_texture( char **texture, t_game *game )
{
	char	**rgb_texture;
	int		color[3];
	int		i;

	i = -1;
	rgb_texture = ft_split(texture[1], ',');
	if (ft_2dstrlen(rgb_texture) != 3)
	{
		free_2dstr(texture);
		free_2dstr(rgb_texture);
		process_error(COLOR_ERROR, game);
	}
	while (rgb_texture[++i])
	{
		if (!ft_strdigit(rgb_texture[i]))
		{
			free_2dstr(rgb_texture);
			free_2dstr(texture);
			process_error(COLOR_ERROR, game);
		}
		color[i] = ft_atoi(rgb_texture[i]);
	}
	return (free_2dstr(rgb_texture), rgb_to_hex(color, game, texture));
}
