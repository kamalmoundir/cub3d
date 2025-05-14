/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:15:37 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/01 18:50:17 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "types.h"

typedef struct s_map
{
	int	width;
	int	height;
	char **grid;
	char **copy_grid;
	char *path;

}	t_map;

//initialize map struct with default value
bool	init_def_map(t_map *map);
bool	init_map(t_map *map, char **data_raw, char *path);

//validate map function
int		check_empty_line(t_map *map);
int		check_caracters(t_map *map);
int		check_multi_players(t_map *map);
int		check_borders(t_map *map);

// get map hight and width
bool 	get_map_path(char *map_path, t_map *map);
int		get_map_hight(t_map *map);
int		get_map_width(t_map *map);

//extract map Grid from raw data
bool 	ft_extract_map(char **raw_lines,t_map *map);

#endif