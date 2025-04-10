/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:27:50 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/09 15:45:16 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *nptr)
{
	size_t	i;
	int sign;
	int ret;

	i = 0;
	ret = 0;
	sign = 1;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i]=='-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
		ret = ret * 10 + (nptr[i++] - '0');
	return (ret * sign);
}
