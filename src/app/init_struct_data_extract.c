/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_data_extract.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:07:23 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/02 13:47:45 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "config.h"
#include "game.h"
#include "player.h"

//todo change printf with other function  

//initialize map struct from data extracted
bool init_map(t_map *map, char **data_raw, char *path)
{
    
    if(!ft_extract_map(data_raw, map))
        return (printf("error extract map from data raw\n"),false);
    map->height = get_map_hight(map);
    map->width = get_map_width(map);
    if(!get_map_path(path,map))
        return(printf("ERROR get map path\n"),false);
    return (true);
}

//initialize config struct
bool init_config(t_config *config, char **data_raw)
{
    if(!extract_config(data_raw, config))
       return(printf("Config extraction failed\n"), false);
    if(!validate_config(config))
        return(printf("ERROR no valid config value\n"), false);
    return (true);
}
