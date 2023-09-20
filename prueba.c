#include <stdlib.h>
#include <stdio.h>
#include "incs/cub3d.h"

int ft_isspace(int c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

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

char	**split_textures( char *str )
{
	int		len;
	char	**dst;

    printf("<%s>\n", str);
	len = count_values(str);
    printf("len = <%d>\n", len);
	if (!str || len > 2)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * len + 1);
	if (!dst)
		return (NULL);

}

int main(int argc, char **argv)
{
    //split_textures("        NO                                      textura             hgewdhgdafwhg asgfhjadgfjh \n");
	

}