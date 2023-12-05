/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:13:07 by sperez-p          #+#    #+#             */
/*   Updated: 2023/12/05 12:25:55 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

static void	ft_mlx_xpm_file_to_image( t_img *img, char *dir, t_game *game, char **texture )
{
	img->img = mlx_xpm_file_to_image(game->mlx_data->mlx, dir, &img->width,
			&img->height);
	img->bits_per_pixel = 8;
	if (!img->img)
	{
		free_2dstr(texture);
		process_error(INVALID_XPM, game);
	}
}

static void	get_wall_texture( char **texture, t_img *img, t_game *game )
{
	check_extension(texture[1], ".xpm", game, texture);
	ft_mlx_xpm_file_to_image(img, texture[1], game, texture);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

/*
 *
 */
static void	add_texture( char **texture, t_game *game )
{
	if (ft_2dstrlen(texture) == 2)
	{
		if (!ft_strcmp(texture[0], "NO"))
			get_wall_texture(texture, game->textures_data->no, game);
		else if (!ft_strcmp(texture[0], "SO"))
			get_wall_texture(texture, game->textures_data->so, game);
		else if (!ft_strcmp(texture[0], "EA"))
			get_wall_texture(texture, game->textures_data->ea, game);
		else if (!ft_strcmp(texture[0], "WE"))
			get_wall_texture(texture, game->textures_data->we, game);
		else if (!ft_strcmp(texture[0], "C"))
			game->textures_data->c = get_rgb_texture(texture, game);
		else if (!ft_strcmp(texture[0], "F"))
			game->textures_data->f = get_rgb_texture(texture, game);
	}
	else
	{
		if (!ft_strcmp(texture[0], "C"))
			game->textures_data->c = get_rgb_texture_aux(texture, game);
		else if (!ft_strcmp(texture[0], "F"))
			game->textures_data->f = get_rgb_texture_aux(texture, game);
		else
		{
			free_2dstr(texture);
			process_error(INVALID_TEXTURE, game);			
		}
	}
}

/*
 *
 */
static void	texture_filled_checker(t_game *game)
{
	if (!game->textures_data->no || !game->textures_data->so || \
	!game->textures_data->we || !game->textures_data->ea || \
	!game->textures_data->f || !game->textures_data->c)
		process_error(MISSING_TEXTURE, game);
}

void	get_textures( t_game *game )
{
	int		i;
	char	**texture;

	i = -1;
	while (game->textures[++i])
	{
		texture = split_textures(game->textures[i], game);
		if (!texture[0])
			continue ;
		if (!ft_strstr(TEXTURES, texture[0]))
		{
			free_2dstr(texture);
			process_error(INVALID_TEXTURE, game);			
		}
		add_texture(texture, game);
		free_2dstr(texture);
	}
	texture_filled_checker(game);
}
