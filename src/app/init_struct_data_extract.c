/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_data_extract.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:07:23 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/01 18:24:33 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

//todo change printf with other function  
bool init_map(t_map *map, char **data_raw)
{
    
    if(!ft_extract_map(data_raw, map))
        return (printf("error extract map from data raw\n"),false);
    map->height = get_map_hight(map);
    map->width = get_map_width(map);
    
}