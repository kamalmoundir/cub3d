/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_map_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:29:31 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/01 18:55:28 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool verify_map_file(char *map_path)
{
    int fd;
    
    fd = open(map_path, O_RDONLY);
    if (fd == -1)
        return (false);
    close(fd);
    return (true);
}
bool get_map_path(char *map_path, t_map *map)
{
    if (!verify_map_file(map_path))
        return (printf("ERROR Path file \n"), false);
    map->path = ft_strdup(map_path);
    if (!map->path)
        return (printf("ERROR Memory allocation failed\n"), false);
    return (true);
}