/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:57:32 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/15 15:41:37 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map.h"

int	validate_extension(char *s)
{
	char	*tmp;
	char	**str;
	int		i;

	i = 0;
	str = ft_split(s, '/');
	while (str[i])
		i++;
	--i;
	if (!str[i])
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

int	check_empty_line(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	// Correct way
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

static int check_first_last_lines(const char *line)
{
	int j;
	j = 0;
	
	while (line[j])
    {
        if (line[j] != '1' && line[j] != ' ')
            return (1);
        j++;
    }
	return 0;
}

int	check_borders(t_map *map)
{
    int	i;
    int	j;
	
	if(check_first_last_lines(map->grid[0]))
		return(1);
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
	if(check_first_last_lines(map->grid[i-1]))
		return(1);
    return (0);
}

