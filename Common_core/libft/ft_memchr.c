/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:04:22 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/11 12:51:03 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/// @brief Scans for a character in the first n bytes of s.
/// @param s: Pointer to the first element to be checked.
/// @param c: Target character.
/// @param n: Number of bytes to be checked.
/// @return Pointer to the first occurrence of c.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*aux;

	i = 0;
	aux = (unsigned char *) s;
	while (i < n)
	{
		if (aux[i] == (unsigned char) c)
			return ((void *)(aux + i));
		i++;
	}
	return (NULL);
}
