/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:10:15 by sstoev            #+#    #+#             */
/*   Updated: 2025/05/27 16:10:17 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parser.h"
#include "utils.h"

static bool				extract_all_data(char **data_raw, t_map *map, t_config *config, const char *filepath);
static bool				validate_complete_setup(t_map *map, t_player *player, char **data_raw);
static void				cleanup_partial_data(t_map *map, t_config *config, char **data_raw);
static t_parse_result	create_success_result(t_map *map, t_config *config, t_player *player);
static t_parse_result	create_error_result(const char *error_msg);

t_parse_result	parse_cub_file(const char *filepath)
{
	char		**data_raw;
	t_map		map;
	t_config	config;
	t_player	player;

	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&config, 0, sizeof(t_config));
	ft_memset(&player, 0, sizeof(t_player));
	if (!validate_extension((char *)filepath))
		return (create_error_result("Invalid file extension"));
	data_raw = get_raw_lines((char *)filepath);
	if (!data_raw)
		return (create_error_result("Failed to read file"));
	if (!extract_all_data(data_raw, &map, &config, filepath))
	{
		cleanup_partial_data(&map, &config, data_raw);
		return (create_error_result("Failed to parse file data"));
	}
	if (!get_player_pos_dir(&map, &player))
	{
		cleanup_partial_data(&map, &config, data_raw);
		return (create_error_result("Failed to find player position"));
	}
	if (!validate_complete_setup(&map, &player, data_raw))
	{
		cleanup_partial_data(&map, &config, data_raw);
		return (create_error_result("Invalid map or config"));
	}
	free_array(data_raw);
	return (create_success_result(&map, &config, &player));
}

static bool	extract_all_data(char **data_raw, t_map *map, t_config *config, const char *filepath)
{
	init_def_map(map);
	if (!init_map(map, data_raw, (char *)filepath))
		return (false);
	init_def_config(config);
	if (!extract_config(data_raw, config))
		return (false);
	if (!validate_config(config))
		return (false);
	return (true);
}

static bool	validate_complete_setup(t_map *map, t_player *player, char **data_raw)
{
	if (!map_valid_border(data_raw, map))
		return (false);
	map->copy_grid = copy_map(map->grid, get_map_hight(map));
	if (!map->copy_grid)
		return (false);
	path_finder(map->copy_grid, player->position.x, player->position.y);
	if (check_unreacheble_area(map))
		return (false);
	return (true);
}

static void	cleanup_partial_data(t_map *map, t_config *config, char **data_raw)
{
	if (config)
		free_config(config);
	if (map)
	{
		if (map->copy_grid)
			free_array(map->copy_grid);
		if (map->grid)
			free_array(map->grid);
	}
	if (data_raw)
		free_array(data_raw);
}

static t_parse_result	create_success_result(t_map *map, t_config *config, t_player *player)
{
	t_parse_result	result;

	ft_memset(&result, 0, sizeof(t_parse_result));
	result.success = true;
	result.map = *map;
	result.config = *config;
	result.player = *player;
	result.error_msg = NULL;
	return (result);
}

static t_parse_result	create_error_result(const char *error_msg)
{
	t_parse_result	result;

	ft_memset(&result, 0, sizeof(t_parse_result));
	result.success = false;
	result.error_msg = ft_strdup(error_msg);
	return (result);
}
