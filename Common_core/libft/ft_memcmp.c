/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:31:19 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/10 20:34:39 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Compares the first n bytes of s1 to s2.
/// @param s1: Pointer to the first element of the first buffer.
/// @param s2: Pointer to the first element of the second buffer.
/// @param n: Number of bytes to compare.
/// @return =0 if they are equal, >0 if s1>s2, <0 if s1<s2.
int	memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*aux1;
	unsigned char	*aux2;

	i = 0;
	aux1 = (unsigned char *) s1;
	aux2 = (unsigned char *) s2;
	while (i < n)
	{
		if (aux1[i] - aux2[i] != 0)
			return (aux1[i] - aux2[i]);
		i++;
	}
	return (0);
}