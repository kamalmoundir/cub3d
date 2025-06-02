/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_data_extract.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:07:23 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/30 16:51:20 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "game.h"
#include "map.h"
#include "player.h"

bool	init_map(t_map *map, char **data_raw, char *path)
{
	if (!ft_extract_map(data_raw, map))
		return (ft_dprintf(STDERR_FILENO,
				"ERROR\n extract map from data raw\n"), false);
	map->height = get_map_hight(map);
	map->width = get_map_width(map);
	if (!get_map_path(path, map))
		return (ft_dprintf(STDERR_FILENO, "ERROR\n get map path\n"), false);
	return (true);
}

bool	init_config(t_config *config, char **data_raw)
{
	if (!extract_config(data_raw, config))
		return (ft_dprintf(STDERR_FILENO, "ERROR \nConfig extraction failed\n"),
			false);
	if (!validate_config(config))
		return (ft_dprintf(STDERR_FILENO, "ERROR \nno valid config value\n"),
			false);
	return (true);
}
