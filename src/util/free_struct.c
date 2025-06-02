/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:29:26 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/02 17:40:41 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "utils.h"

void	free_config(t_config *config)
{
	if (config)
	{
		if (config->north_texture)
			safe_free((void **)&config->north_texture);
		if (config->south_texture)
			safe_free((void **)&config->south_texture);
		if (config->east_texture)
			safe_free((void **)&config->east_texture);
		if (config->west_texture)
			safe_free((void **)&config->west_texture);
	}
}
