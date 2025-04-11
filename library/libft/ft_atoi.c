/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:40:26 by kmoundir          #+#    #+#             */
/*   Updated: 2024/10/04 22:59:02 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(int c)
{
	if (c == '\r' || c == '\f' || c == ' ' || c == '\n' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	i;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && nptr[i])
	{
		nbr *= 10;
		nbr += nptr[i] - '0';
		i++;
	}
	return (nbr * sign);
}
