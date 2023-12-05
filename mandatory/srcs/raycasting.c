/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:20:47 by sperez-p          #+#    #+#             */
/*   Updated: 2023/12/04 13:20:47 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"
#include <math.h>

static void	get_texture( t_raycast *ray, t_game *game )
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			game->texture = game->textures_data->ea;
		else
			game->texture = game->textures_data->we;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			game->texture = game->textures_data->so;
		else
			game->texture = game->textures_data->no;
	}
}

static void	get_texture_coord( t_raycast *ray, t_game *game )
{
	t_player	*player;

	player = game->player_data;
	get_texture(ray, game);
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)game->texture->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = game->texture->width - ray->tex_x - 1;
	else if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = game->texture->width - ray->tex_x - 1;
}

/*
 * Calcula la distancia proyectada en la direccion de la camara, la altura de la
 * linea y el pixel mas alto y bajo a rellenar en la franja actual
 */
static void	get_wall_projection( t_raycast *ray )
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

int	raycasting( t_game *game )
{
	t_raycast	ray;
	t_player	*player;
	int			x;

	x = 0;
	player = game->player_data;
	while (x < WIDTH)
	{
		get_ray_dir_pos(x, &ray, game->player_data);
		process_dda(&ray, game);
		get_wall_projection(&ray);
		get_texture_coord(&ray, game);
		draw_window(x, &ray, game);
		x++;
	}
	return (0);
}
