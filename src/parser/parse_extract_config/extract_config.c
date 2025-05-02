/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:35:34 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/02 12:20:54 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool extract_config(char **raw_lines, t_config *config)
{
	int i;
	int config_count;

	i = 0;
	config_count = 0;
	//initialize_config(config); initialize it befor function calle
	while (raw_lines[i])
	{
		if (is_empty_line(raw_lines[i]))
			i++;
		if (is_map_line(raw_lines[i]))
			break ;
		if (parse_config_line(raw_lines[i], config))
			config_count++;

		i++;
	}
	if (config_count < 6)
		return (false);

	return (true);
}