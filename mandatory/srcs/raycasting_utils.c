/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:54:45 by sperez-p          #+#    #+#             */
/*   Updated: 2023/12/04 13:58:43 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*
 * Calcula la posicion del rayo en el plano de la camara, las coordenadas de la
 * direccion del rayo y las coordenadas de la posicion del rayo en la cuadricula.
 */
void	get_ray_dir_pos( int x, t_raycast *ray, t_player *player )
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
}

/*
 * Calcula la distancia que el rayo tiene que viajar de una coordenada a otra
 * dentro de la cuadricula.
 */
static void	get_delta_dist( t_raycast *ray )
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = exp(30);
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = exp(30);
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
}

/*
 * Calcula la distancia que tiene que recorrer el rayo desde la posicion
 * inicial al siguiente valor de coordenadas para ambos ejes.
 */
static void	get_side_dist( t_raycast *ray, t_player *player )
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) * \
		ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * \
		ray->delta_dist_y;
	}
}

static void	get_hit( t_raycast *ray, t_game *game)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game-> map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	process_dda( t_raycast *ray, t_game *game )
{
	get_delta_dist(ray);
	get_side_dist(ray, game->player_data);
	get_hit(ray, game);
}
