/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:27:47 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/10 20:45:13 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Fills the first n bytes of s with the constant byte c
/// @param s: pointer to the first element that will be set.
/// @param c: character that will be filled in s.
/// @param n: number of bytes to be filled.
/// @return Pointer to the first filled element.
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*aux;

	i = 0;
	aux = (unsigned char *) s;
	while (i < n)
		aux[i++] = c;
	return (s);
}
