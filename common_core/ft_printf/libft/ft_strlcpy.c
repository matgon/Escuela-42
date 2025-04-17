/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:12:20 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/10 21:03:08 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief copies up to size - 1 characters from the NUL-terminated
///			 string src to dst, NUL-terminating the result.
/// @param dest: pointer to the first element of the destination.
/// @param src: pointer to the first element that will be copied.
/// @param size: number of bytes to be copied.
/// @return Total length of the string it tried to create.
size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
