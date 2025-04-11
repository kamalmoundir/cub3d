/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:54:25 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/11 12:52:37 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_empty_line(t_cub3d *cub)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		count = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == ' ')
				count++;
			j++;
		}
		if (j == count)
			return (1);
		i++;
	}
	return (0);
}

int	check_caracters(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] != ' ' && cub->map[i][j] != 'N'
				&& cub->map[i][j] != 'S' && cub->map[i][j] != 'E'
				&& cub->map[i][j] != 'W' && cub->map[i][j] != '0'
				&& cub->map[i][j] != '1')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}
int	check_multi_players(t_cub3d *cub)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'E' || cub->map[i][j] == 'N'
				|| cub->map[i][j] == 'W' || cub->map[i][j] == 'S')
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (0);
	else
		return (1);
}
// TODO: we have to ignore spaces in each line
int	check_borders(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (cub->map[0][j])
	{
		if (cub->map[0][j] != '1')
			return (1);
		j++;
	}
	while (cub->map[i])
	{
		if (cub->map[i][0] != '1' || cub->map[i][ft_strlen(cub->map[i])
			- 1] != '1')
		{
			printf("%c     %c  ", cub->map[i][0],
				cub->map[i][ft_strlen(cub->map[i]) - 1]);
			return (i);
		}
		i++;
	}
	j = 0;
	while (cub->map[i - 1][j])
	{
		if (cub->map[i - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	get_map_hight(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (cub->map[i])
	{
		i++;
	}
	return (i);
}

int	get_map_width(t_cub3d *cub)
{
	int				i;
	unsigned int	max_width;

	i = -1;
	max_width = 0;
	while (cub->map[++i])
	{
		if (max_width < ft_strlen(cub->map[i]))
			max_width = ft_strlen(cub->map[i]);
	}
	return (max_width);
}

char	**copy_map(char **map, int rows)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	validate_extension(char *s)
{
	char	*tmp;
	char	**str;
	int		i;

	i = 0;
	str = ft_split(s, '/');
	while (str[i])
		i++;
	--i;
	if (!str[i])
		return (0);
	if (ft_strlen(str[i]) == 4)
		return (free_array(str), printf("Error\nBad extension\n"), 0);
	if (ft_strncmp(str[1], ".cub", 4) == 0)
		return (free_array(str), printf("Error\nBad extension\n"), 0);
	tmp = ft_strnstr(str[i], ".cub", ft_strlen(str[i]));
	if (tmp == NULL || *tmp == '\0' || *(tmp + 4) != '\0')
		return (free_array(str), printf("Error\nBad extension\n"), 0);
	return (free_array(str), 1);
}

void	path_finder(char **map, int x, int y)
{
	if (map == NULL)
		return ;
	if (x < 0 || x >= (int)ft_strlen(map[y]) || y < 0 || !map[y]
		|| map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == ' ')
		return ;
	map[y][x] = 'V';
	path_finder(map, x + 1, y);
	path_finder(map, x - 1, y);
	path_finder(map, x, y + 1);
	path_finder(map, x, y - 1);
}

t_player	get_player_pos_dir(t_cub3d *cub)
{
	int			i;
	int			j;
	t_player	player;

	i = 0;
	player.pos_x = -1;
	player.pos_y = -1;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' || cub->map[i][j] == 'E'
				|| cub->map[i][j] == 'W')
			{
				player.pos_x = j;
				player.pos_y = i;
				player.init_dir = cub->map[i][j];
				return (player);
			}
			j++;
		}
		i++;
	}
	return (player);
}
int	check_unreacheble_area(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
char **get_raw_line(char *str)
{
	int fd;
	char **raw_lines;
	fd = open("assets/maps/map1.cub", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    raw_lines = array_map(fd);
	return (raw_lines);
}
// this function is "optional"!!
/*t_player get_init_dir_pl(char **map)
{
	int i;
	int j;
	t_player player;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				player.init_dir = map[i][j];
				return (player);
			}
			j++;
		}
		i++;
	}
	return (player);
}*/