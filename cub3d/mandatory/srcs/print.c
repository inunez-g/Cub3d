/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:08:17 by inunez-g          #+#    #+#             */
/*   Updated: 2023/10/05 11:29:03 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	print_list( t_var *vars )
{
	t_list	*tmp;

	tmp = vars->lst_map;
	while (tmp)
	{
		printf("%s", tmp->line);
		tmp = tmp->next;
	}
}

void	print_2dstr( char **str )
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		printf("<%s>\n", str[i]);
}
