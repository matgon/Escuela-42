/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:27:50 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/11 12:25:16 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Converts a number passed as an string to an integer. 
/// @param nptr: String
/// @return Converted integer
int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		ret;

	i = 0;
	ret = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
		ret = ret * 10 + (nptr[i++] - '0');
	return (ret * sign);
}
