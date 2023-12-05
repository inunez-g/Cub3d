/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:51:18 by sperez-p          #+#    #+#             */
/*   Updated: 2023/12/04 18:38:37 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

static void	my_mlx_pixel_put( t_game *game, int x, int y, int color )
{
	char	*dst;

	dst = game->mlx_data->addr + (y * game->mlx_data->line_length + x * \
	(game->mlx_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static unsigned int	get_image_color( t_img *texture, int x, int y )
{
	char			*dst;
	unsigned int	color;

	dst = texture->addr + (y * texture->line_length + x * \
	(texture->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	draw_window( int x, t_raycast *ray, t_game *game )
{
	int	y;

	y = -1;
	ray->step = 1.0 * game->texture->height / ray->line_height;
	ray->tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * \
	ray->step;
	while (++y < ray->draw_start)
		my_mlx_pixel_put(game, x, y, game->textures_data->c);
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (game->texture->height - 1);
		ray->tex_pos += ray->step;
		my_mlx_pixel_put(game, x, y, get_image_color(game->texture, ray->tex_x, \
		ray->tex_y));
		y++;
	}
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(game, x, y, game->textures_data->f);
		y++;
	}
}
