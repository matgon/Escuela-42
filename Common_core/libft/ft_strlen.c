/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:25:55 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/10 20:52:16 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Calculate the length of a string.
/// @param s: string to be calculated.
/// @return size of the string excluding the terminating byte.
size_t	ft_strlen(const char *s)
{
	size_t ret;

	ret = 0;
	while (s[ret])
		ret++;
	return (ret);
}
