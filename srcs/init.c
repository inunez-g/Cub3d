/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:02:51 by inunez-g          #+#    #+#             */
/*   Updated: 2023/09/20 12:19:57 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"
#include <fcntl.h>

void    init_textures(t_vars	*vars)
{
    vars->my_textures.no.name = ft_strdup("NO");
    vars->my_textures.so.name = ft_strdup("SO");
    vars->my_textures.ea.name = ft_strdup("EA");
    vars->my_textures.we.name = ft_strdup("WE");
    vars->my_textures.f.name = ft_strdup("F");
    vars->my_textures.c.name = ft_strdup("C");
    vars->my_textures.no.value = NULL;
    vars->my_textures.so.value = NULL;
    vars->my_textures.ea.value = NULL;
    vars->my_textures.we.value = NULL;
    vars->my_textures.f.value = NULL;
    vars->my_textures.c.value = NULL;
    vars->my_textures.filled = 0;
}