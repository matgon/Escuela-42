/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:39:44 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/09 19:13:34 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*aux1;
	unsigned char	*aux2;

	i = 0;
	aux1 = (unsigned char *) dest;
	aux2 = (unsigned char *) src;
	if (src < dest)
	{
		while (n)
		{
			aux1[n - 1] = aux2[n - 1];
			n--;
		}
	}
	else if (src > dest)
	{
		while (i < n)
		{
			aux1[i] = aux2[i];
			i++;
		}
	}
	return (dest);
}
