/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:33:17 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/11 12:04:42 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies n bytes from memory area src to memory area dest. 
///			The memory areas must not overlap.  Use ft_memmove if
///			the memory areas do overlap.
/// @param dest: pointer to the first element where the result will be stored.
/// @param src: pointer to the first element to be copied.
/// @param n: number of bytes to be copied.
/// @return pointer to the first element of dest.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*aux1;
	unsigned char	*aux2;

	if (n == 0 || dest == src)
		return (dest);
	i = 0;
	aux1 = (unsigned char *) dest;
	aux2 = (unsigned char *) src;
	while (i < n)
	{
		aux1[i] = aux2[i];
		i++;
	}
	return (dest);
}
