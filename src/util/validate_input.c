/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:14 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/15 16:58:59 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "map.h"
#include "utils.h"
#include "player.h"

static void	free_data(t_config *config, t_map *map, char **data_raw)
{
	free_config(config);
	free_array(map->copy_grid);
	free_array(map->grid);
	safe_free((void**)&map);
	free_array(data_raw);
}

static bool	map_valid_border(char **data_raw, t_map *map)
{
	if (check_caracters(map) || check_multi_players(map) || check_borders(map)
		|| check_empty_line(map))
		return (free_array(map->grid), safe_free((void**)&map), free_array(data_raw), false);
	return (true);
}

static bool validate_map_path(t_map *map, t_player player)
{
    printf("\n \n");
    (void)player;
    map->copy_grid = copy_map(map->grid, get_map_hight(map));
    if (!map->copy_grid)
        return (printf("error copy grid\n"),false);
   
    
   
	
    //path_finder(map->copy_grid, player.position.x, player.position.y);
   // if (check_unreacheble_area(map))
      //  return (printf("error unreacheble area\n"),false);
    return (true);
}

bool validate_input(char *path)
{
    char		**data_raw;
    t_map		*map;
    t_config	*config;
    t_player	player;

    if (!validate_extension(path))
      return (false);
   data_raw = get_raw_lines(path);
   
    if (!data_raw)
        return (false);
        
   map = malloc(sizeof(t_map));
    if (!map || !ft_extract_map(data_raw, map))
        return (free_array(data_raw), safe_free((void**)&map), false);
    if (!map_valid_border(data_raw, map))
        return (false);
    config = malloc(sizeof(t_config));
    if (!config || !extract_config(data_raw, config) || !validate_config(config))
        return (free_config(config), free_array(map->grid), 
            safe_free((void **)&map), free_array(data_raw), false);
    if (!get_player_pos_dir(map, &player) || !validate_map_path(map, player))
        return (free_config(config), free_array(map->copy_grid), 
            free_array(map->grid), safe_free((void**)&map), free_array(data_raw), false);
    free_data(config, map, data_raw);
    return (true);
}
