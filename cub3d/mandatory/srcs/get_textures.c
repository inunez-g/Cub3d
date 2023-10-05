#include "../incs/cub3d.h"


int	ft_atoi(const char *str)
{
	int	result;
	ssize_t	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = (*str++ - 48) + (result * 10);
	return (result * sign);
}

int	check_hex(int nbr)
{
	return (nbr >= 0 && nbr <= 255);
}

unsigned int rgbToHex(int red, int green, int blue, t_var *vars) {
	if (!check_hex(red) || !check_hex(red) || !check_hex(red))
		process_error(COLOR_ERROR, vars);
    return (1  << 24 | (red & 0xFF) << 16) | ((green & 0xFF) << 8) | (blue & 0xFF);
}


static void	add_texture( char **texture, t_var *vars)
{
	if (ft_2dstrlen(texture) > 4)
		process_error(INVALID_TEXTURE, vars);
	else if (!ft_strcmp(texture[0], "NO") && ft_2dstrlen(texture) == 2)
		vars->textures->no = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "SO") && ft_2dstrlen(texture) == 2)
		vars->textures->so = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "EA") && ft_2dstrlen(texture) == 2)
		vars->textures->ea = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "WE") && ft_2dstrlen(texture) == 2)
		vars->textures->we = ft_strdup(texture[1]);
	if (ft_2dstrlen(texture) == 2)
	{
		if (!ft_strcmp(texture[0], "C"))
			vars->textures->c = 1;
		else if (!ft_strcmp(texture[0], "F"))
			vars->textures->f = 2;
	} else
	{
		int	i;
		
		i = 1;
		int j = 0;
		int	textures1[3];
		while (texture[i])
		{
			char*tmp;
			tmp = texture[i];
			texture[i] = ft_strtrim(texture[i], ",");
			free(tmp);
			textures1[j] = ft_atoi(texture[i]);
			j++;
			i++;
		}
		if (!ft_strcmp(texture[0], "C"))
			vars->textures->c = rgbToHex(textures1[0], textures1[1], textures1[2], vars);

		else if (!ft_strcmp(texture[0], "F"))
			vars->textures->f = rgbToHex(textures1[0], textures1[1], textures1[2], vars);

	}

}

/* IMPORTANTE 
	una vez spliteada la textura, si es NSWE solo puede ser 2, si es CF solo puede ser 4 la longitud
*/
void	get_textures( t_var *vars )
{
	int		i;
	char	**texture;

	i = 0;
	while (i < vars->map_index)
	{
		if (!ft_strcmp(vars->map[i], "\n"))
		{
			i++;
			continue ;
		}
		texture = split_textures(vars->map[i], vars);
		if (!ft_strstr(TEXTURES, texture[0]))
			process_error(INVALID_TEXTURE, vars);		
		add_texture(texture, vars);
		free_2dstr(texture);
		texture = NULL;
		i++;
	}
}