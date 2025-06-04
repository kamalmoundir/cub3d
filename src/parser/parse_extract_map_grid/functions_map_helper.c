/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_map_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:29:31 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/04 15:31:48 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map.h"

static bool	verify_map_file(char *map_path);
static int	check_first_last_lines(const char *line);

int	validate_extension(char *s)
{
	char	*tmp;
	char	**str;
	int		i;

	i = -1;
	str = ft_split(s, '/');
	if (!verify_map_file(s))
	{
		return (ft_dprintf(STDERR_FILENO, "Error:\n opening file: %s\n", s),
			free_array(str), 0);
	}
	while (str[++i])
		;
	if (!str[--i])
		return (0);
	if (ft_strlen(str[i]) <= 4)
		return (free_array(str), printf("Error\nBad extension\n"), 0);
	if (ft_strncmp(str[i] + ft_strlen(str[i]) - 4, ".cub", 4) != 0)
		return (free_array(str), printf("Error\nBad extension\n"), 0);
	tmp = ft_strnstr(str[i], ".cub", ft_strlen(str[i]));
	if (tmp == NULL || *tmp == '\0' || *(tmp + 4) != '\0')
		return (free_array(str), printf("Error\nBad extension\n"), 0);
	return (free_array(str), 1);
}

static bool	verify_map_file(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

bool	get_map_path(char *map_path, t_map *map)
{
	if (!verify_map_file(map_path))
		return (ft_dprintf(STDERR_FILENO, "ERROR:\n Path file \n"), false);
	map->path = ft_strdup(map_path);
	if (!map->path)
		return (ft_dprintf(STDERR_FILENO,
				"ERROR:\n Memory allocation failed\n"), false);
	return (true);
}

int	check_borders(t_map *map)
{
	int	i;
	int	j;

	if (check_first_last_lines(map->grid[0]))
		return (1);
	if (check_cell_near_empty(map))
		return (1);
	i = 1;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j] == ' ' && map->grid[i][j])
			j++;
		if (map->grid[i][j] != '1')
			return (i);
		j = ft_strlen(map->grid[i]) - 1;
		while (j >= 0 && map->grid[i][j] == ' ')
			j--;
		if (j >= 0 && map->grid[i][j] != '1')
			return (i);
		i++;
	}
	if (check_first_last_lines(map->grid[i - 1]))
		return (1);
	return (0);
}

static int	check_first_last_lines(const char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] != '1' && line[j] != ' ')
			return (1);
		j++;
	}
	return (0);
}
