/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:03:04 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/13 10:18:29 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Allocate 'nmemb*size' bytes of memory and initializes them to 0.
/// @param nmemb: Number of elements.
/// @param size: Size of each element.
/// @return Pointer to the first element.
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t	n_bytes;

	if (nmemb == 0 || size == 0)
	{
		ret = malloc(1);
		n_bytes = 1;
	}
	else
	{
		n_bytes = nmemb * size;
		if (n_bytes / nmemb != size)
			return (NULL);
		ret = malloc(n_bytes);
	}
	if (!ret)
		return (NULL);
	ft_bzero(ret, n_bytes);
	return (ret);
}
