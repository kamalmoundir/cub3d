/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:42:52 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/30 19:29:19 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map.h"

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

static void	ft_copy_map(char **raw_lines, char **grid, const int start_index,
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

bool	ft_extract_map(char **raw_lines, t_map *map)
{
	int		i;
	int		start_index;
	int		map_lines;
	char	**grid;

	if (!map || !raw_lines)
		return (false);
	start_index = ft_map_start(raw_lines);
	if (start_index == -1)
		return (false);
	map_lines = 0;
	i = start_index;
	while (raw_lines[i] && is_map_line(raw_lines[i]))
	{
		map_lines++;
		i++;
	}
	grid = malloc(sizeof(char *) * (map_lines + 1));
	if (!grid)
		return (false);
	ft_copy_map(raw_lines, grid, start_index, map_lines);
	map->grid = grid;
	return (true);
}

char	**get_raw_lines(char *filepath)
{
	int		fd;
	char	**raw_lines;
	int		size;

	size = get_number_line_file(filepath);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(STDERR_FILENO, "Error opening file: %s\n", filepath);
		return (NULL);
	}
	raw_lines = array_map(fd, size);
	if (!raw_lines)
		return (NULL);
	close(fd);
	return (raw_lines);
}

int	check_unreachable_area(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->copy_grid[i])
	{
		j = 0;
		while (map->copy_grid[i][j])
		{
			if (map->copy_grid[i][j] == '0')
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
