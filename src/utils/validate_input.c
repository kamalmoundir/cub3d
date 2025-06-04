/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:14 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/04 12:24:13 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "map.h"
#include "player.h"
#include "utils.h"

static bool	validate_grid(char **data_raw, t_map *map);
static bool	check_conf(t_config *config, t_map *map, char **data_raw);
static bool	validate_map_path(t_map *map, t_player player, char **data_raw);
static bool	map_valid_border(char **data_raw, t_map *map);

bool	validate_input(char *path)
{
	char		**data_raw;
	t_map		map;
	t_config	config;
	t_player	player;
	char		*file;

	if (!validate_extension(path))
		return (false);
	data_raw = get_raw_lines(path);
	if (!data_raw)
		return (false);
	if (!validate_grid(data_raw, &map))
		return (false);
	if (!get_player_pos_dir(&map, &player) || !validate_map_path(&map, player,
			data_raw))
		return (clean_up_all_resources(NULL, &map, NULL, data_raw), false);
	if (!check_conf(&config, &map, data_raw))
		return (false);
	clean_up_all_resources(NULL, &map, &config, data_raw);
	return (true);
}

static bool	validate_grid(char **data_raw, t_map *map)
{
	init_def_map(map);
	if (!ft_extract_map(data_raw, map) || !map_valid_border(data_raw, map))
	{
		ft_dprintf(STDERR_FILENO, "ERROR :\nFailed to validate map grid\n");
		return (clean_up_all_resources(NULL, map, NULL, data_raw), false);
	}
	return (true);
}

static bool	check_conf(t_config *config, t_map *map, char **data_raw)
{
	init_def_config(config);
	if (!extract_config(data_raw, config) || !validate_config(config))
	{
		ft_dprintf(STDERR_FILENO, "ERROR :\nFailed to validate config\n");
		return (clean_up_all_resources(NULL, map, config, data_raw), false);
	}
	return (true);
}

static bool	map_valid_border(char **data_raw, t_map *map)
{
	if (check_caracters(map) || check_multi_players(map) || check_borders(map)
		|| check_empty_line(map) || check_cell_near_empty(map))
		return (false);
	return (true);
}

static bool	validate_map_path(t_map *map, t_player player, char **data_raw)
{
	if (!map_valid_border(data_raw, map))
		return (false);
	map->copy_grid = copy_map(map->grid, get_map_hight(map));
	if (!map->copy_grid)
		return (ft_dprintf(STDERR_FILENO, "ERROR :\nFailed to copy map grid\n"),
			false);
	path_finder(map->copy_grid, player.position.x, player.position.y);
	if (check_unreachable_area(map))
		return (ft_dprintf(STDERR_FILENO,
				"ERROR :\nUnreachable area detected\n"), false);
	return (true);
}
