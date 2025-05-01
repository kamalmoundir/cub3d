/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:54:25 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/01 18:22:20 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

#include "map.h"
#include "player.h"
#include "gnl.h"
#include "game.h"

int	get_map_hight(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[i])
	{
		i++;
	}
	return (i);
}

int	get_map_width(t_map *map)
{
	int				i;
	unsigned int	max_width;

	if(!map)
		return (-1);
	i = -1;
	max_width = 0;
	while (map->grid[++i])
	{
		if (max_width < ft_strlen(map->grid[i]))
			max_width = ft_strlen(map->grid[i]);
	}
	return (max_width);
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

//should be inittilize  plyer struct befor call this function
bool get_player_pos_dir(t_map *map, t_player *player)
{
    int i;
    int j;
    int found;
    
    i = -1;
    found = 0;
    while (map->grid[++i])
    {
        j = -1;
        while (map->grid[i][++j])
        {
            if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S' || 
                map->grid[i][j] == 'E' || map->grid[i][j] == 'W')
            {
                if (found)
                    return (false); 
                player->position.x= j;
                player->position.y= i;
                player->init_dir = map->grid[i][j];
                found = 1;
            }
        }
    }
    return (true);
}

int check_unreacheble_area(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->copy_grid[i])
	{
		j = 0;
		while (map->copy_grid[i][j])
		{
			if (map->copy_grid[i][j] == '0')
			{
				printf("(%d ,%d)",i,j);
				return (i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char **get_raw_lines(char *filepath)
{
    int fd;
    char **raw_lines;
    
    int size =	get_number_line_file(filepath);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (NULL);
    }
    raw_lines = array_map(fd,size);
    close(fd);
    return (raw_lines);
}
