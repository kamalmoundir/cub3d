/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:57:32 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/02 16:35:03 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map.h"
#include <unistd.h>

static bool	funct_helper(t_map *map, int i, int j);

int	check_empty_line(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		count = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == ' ')
				count++;
			j++;
		}
		if (j == count)
			return (1);
		i++;
	}
	return (0);
}

int	check_caracters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] != ' ' && map->grid[i][j] != 'N'
				&& map->grid[i][j] != 'S' && map->grid[i][j] != 'E'
				&& map->grid[i][j] != 'W' && map->grid[i][j] != '0'
				&& map->grid[i][j] != '1')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_multi_players(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'E' || map->grid[i][j] == 'N'
				|| map->grid[i][j] == 'W' || map->grid[i][j] == 'S')
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (0);
	else
		return (1);
}

bool	check_cell_near_empty(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->grid[++i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if (map->grid[i][j] != '1' && map->grid[i][j] != ' ')
			{
				if (i == 0 || j == 0)
					return (true);
				if (!map->grid[i + 1] || !map->grid[i][j + 1] || map->grid[i][j
					+ 1] == ' ')
					return (true);
				if (j > 0 && map->grid[i][j - 1] == ' ')
					return (true);
				if (funct_helper(map, i, j))
					return (true);
			}
		}
	}
	return (false);
}

static bool	funct_helper(t_map *map, int i, int j)
{
	int	next_row_len;
	int	prev_row_len;

	next_row_len = 0;
	prev_row_len = 0;
	if (map->grid[i + 1])
	{
		next_row_len = ft_strlen(map->grid[i + 1]);
		if (j >= next_row_len || map->grid[i + 1][j] == ' ')
			return (true);
	}
	if (i > 0)
	{
		prev_row_len = ft_strlen(map->grid[i - 1]);
		if (j >= prev_row_len || map->grid[i - 1][j] == ' ')
			return (true);
	}
	return (false);
}
