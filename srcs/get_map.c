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
			printf("ascii %d\n", str[i]);
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
	printf("FILL TEXTURES\n");
	int	len;
	int	i;
	int start;
	int	j;

	i = 0;
	len = 0;
	j = 0;
	printf("str[i] = %s\n", str);
	while (str[i])
	{
		while (ft_isspace(str[i]) && str[i])
			i++;
		start = i;
		while (!ft_isspace(str[i]) && str[i])
			i++;
		dst[j] = splitdup(str, start, i);
		printf("dst[j] = <%s>\n", dst[j]);
		if (ft_strstr(dst[0], TEXTURES))
			process_error(INVALID_TEXTURE);
		j++;
	}
	dst[j] = NULL;
	return (dst);
}

char	**split_textures( char *str )
{
	int		len;
	char	**dst;

	len = count_values(str);
	printf("len = %d\n", len);
	printf("str = %s\n", str);
	if (!str || len > 2)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (len + 1));
	if (!dst)
	{
			printf("len = %d\n", len);
		return (NULL);
	}
	printf("len = %d\n", len);
	dst = fill_textures(str, dst);
	return (dst);
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

void	super_printf(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
	{
		printf("[%s]\n", str[i]);
		i++;
	}
}

void	lst_to_array(t_vars *vars)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = vars->lst_map;
	vars->my_map.map = (char **)malloc(sizeof(char *)
			* (vars->my_map.lines + 1));
	if (!vars->my_map.map)
		return ;
	while (i < vars->my_map.lines)
	{
		vars->my_map.map[i] = ft_strdup((char *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	vars->my_map.map[vars->my_map.lines] = NULL;
	super_printf(vars->my_map.map);
	printf("%s\n", vars->my_map.map[3]);
	//is_map_correct(vars, i);
}

void	read_map(t_vars	*vars)
{
	char	*line;
	int len;
	int i;
	
	vars->my_map.lines = 0;
	while (1)
	{
		line = NULL;
		line = get_next_line(vars->my_map.fd);
		if (line != NULL && ft_strlen(line) > 0)
		{
			if (ft_strlen(line) == 1 && line[0] == '\n')
				continue;
			else
			{
				len = ft_strlen(line) - 1;
				//if (len != vars->my_map.cols && vars->my_map.cols != 0)
					//mapa_invalido();
				//vars->my_map.cols = len;
				ft_lstadd_back(&vars->lst_map, ft_lstnew(ft_strdup(line)));
				free(line);
				vars->my_map.lines +=1;
				//vars->my_map.rows += 1;
			}
		}
		else
			break ;
	}
	close(vars->my_map.fd);
	lst_to_array(vars);
	i = 0;
	char **dest;
	while (vars->my_map.map[i])
	{
		dest = split_textures(vars->my_map.map[i]);
		if (!dest)
			process_error(INVALID_EXTENSION);
		
	}

	printf("hbdsjhjfhsbj\n");
	super_printf(dest);
}

void	give_value( char **dest, t_vars *vars )
{
	if (ft_strcmp(dest[0], "NO"))
		vars->my_textures.no = ft_strdup(dest[1]);
	else if (ft_strcmp(dest[0], "SO"))
		vars->my_textures.so = ft_strdup(dest[1]);
	else if (ft_strcmp(dest[0], "EA"))
		vars->my_textures.ea = ft_strdup(dest[1]);
	else if (ft_strcmp(dest[0], "WE"))
		vars->my_textures.we = ft_strdup(dest[1]);
	else if (ft_strcmp(dest[0], "F"))
		vars->my_textures.f = ft_strdup(dest[1]);
	else if (ft_strcmp(dest[0], "C"))
		vars->my_textures.c = ft_strdup(dest[1]);
}



int	get_map( char *file, t_vars *map_utils )// void o int -> Si returnea 0 todo perf. Si returnea -1/1 o lo que sea error y en el main se termina el programa
{
	check_extension(file, ".cub");
	map_utils->my_map.fd = open(file, O_RDONLY);
	if (map_utils->my_map.fd == -1)
	{
		process_error(INVALID_FILE);
		printf("Mal");
		return (-1);
	}
	else
	{
		init_textures(map_utils);
		read_map(map_utils);
	}
	printf("Bien");
	return (0);
}

/*void	bordes_validos(t_vars *vars, int i)
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
}*/
