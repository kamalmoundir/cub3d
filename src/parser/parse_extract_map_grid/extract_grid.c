/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:42:52 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/15 16:55:51 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	ft_map_start(char **raw_lines)
{
	int	i;
	int	index;

	i = 0;
	index = -1;
	i = 0;
	index = -1;
	while (raw_lines[i])
	{
		if (is_map_line(raw_lines[i]))
		{
			index = i;
			break ;
		}
		i++;
	}
	return (index);
}

static void 	ft_copy_map(char **raw_lines, char **grid, const int start_index,
		const int map_lines)
{
	int	i;

	i = -1;
	while (++i < map_lines)
	{
		grid[i] = ft_strdup(raw_lines[start_index + i]);
		if (!grid[i])
		{
			while (--i >= 0)
				free(grid[i]);
			free(grid);
			return ;
		}
	}
    grid[i] = NULL;

		

	
}

bool ft_extract_map(char **raw_lines,t_map *map)
{
	int		i;
	int		start_index;
	int		map_lines;
	char	**grid;
	
	if(!map || !raw_lines)
		return (false);
	start_index = ft_map_start(raw_lines);
	if (start_index == -1)
		return (false);
	map_lines = 0;
	i = start_index;
	while (raw_lines[i] && is_map_line(raw_lines[i]))
		{map_lines++; i++;}
	grid = malloc(sizeof(char *) * (map_lines + 1));
	if (!grid)
		return (false);
    ft_copy_map(raw_lines,grid, start_index, map_lines);
	map->grid = grid;
	return (true);
}
