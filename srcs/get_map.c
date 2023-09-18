/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:22:49 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/18 01:09:01 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"
#include <fcntl.h>

/*
 * GET TEXTURES.SPLIT. CHECKEO DE VALORES 
 */
static int	count_values( char *str )
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		while (ft_isspace(str[i]) && str[i])
			i++;
		if (!ft_isspace(str[i]) && str[i])
		{
			len++;
			while (!ft_isspace(str[i]) && str[i])
				i++;
		}
	}
	return (len);
}

static char	*splitdup(const char *s, size_t start, size_t finish)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!dest)
		return (NULL);
	while (start < finish)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

char	**fill_textures( char *str, char **dst )
{
	int	len;
	int	i;
	int start;
	char	textures[][3] = {"NO", "SO", "WE", "EA"};
	int	j;

	i = 0;
	len = 0;
	j = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]) && str[i])
			i++;
		start = i;
		while (!ft_isspace(str[i]) && str[i])
			i++;
		dst[j] = splitdup(str, start, i);
		if (ft_strcmp(dst, TEXTURES))
			process_error(INVALID_TEXTURE);
     
	}
}

char	**split_textures( char *str )
{
	int		len;
	char	**dst;

	len = count_values(str);
	if (!str || len > 2)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * len + 1);
	if (!dst)
		return (NULL);
	

}


/*
 * Checks if the given file has a specified extension incluiding the dot.
 * If either pointer is NULL, of ir they are not equal, exits the program with
 * an INVALID_EXTENSION code.
 * Parameters:
 *     file: pointer to the file name to be checked
 *     extension: pointer to he expected file extension
 */
void	check_extension( char *file, char *extension )
{
	char	*file_extension;

	if (!file || !extension)
		process_error(INVALID_EXTENSION);
	file_extension = ft_strrchr(file, '.');
	if (ft_strcmp(extension, file_extension))
		process_error(INVALID_EXTENSION);
}


int	get_map( char *file, t_map *map_utils )// void o int -> Si returnea 0 todo perf. Si returnea -1/1 o lo que sea error y en el main se termina el programa
{
	check_extension(file, ".cub");
	map_utils->fd = open(file, O_RDONLY);
	if (map_utils->fd == -1)
	{
		process_error(INVALID_FILE);
		printf("Mal");
		return (-1);
	}
	else
	{

	}
	printf("Bien");
	return (0);
}

void	read_map(fd)
{
	char	*line;
	int i;
	
	while (1)
	{
		line = NULL;
		line = get_next_line(fd);
		if (line != NULL && ft_strlen(line) > 0)
		{
			pass_spaces
		}
	}
}

void	bordes_validos(t_vars *vars, int i)
{
	int	j;

	j = vars->my_map.rows - 1;
	while (i < vars->my_map.cols)
	{
		if (vars->my_map.map[0][i] == '1' && vars->my_map.map[j][i] == '1')
			i++;
		else
			mapa_invalido();
	}
	j = vars->my_map.cols - 1;
	i = 0;
	while (i < vars->my_map.rows)
	{
		if (vars->my_map.map[i][0] == '1' && vars->my_map.map[i][j] == '1')
			i++;
		else
			mapa_invalido();
	}
}
