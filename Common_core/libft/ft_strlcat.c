/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:06:50 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/10 22:07:00 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/// @brief appends the NUL-terminated string src to the end of dst. 
///			It will append at most size - strlen(dst) - 1 bytes, 
///			NUL-terminating the result. 
/// @param dest: pointer to the first element of the destination.
/// @param src: pointer to the first element that will be concatenated.
/// @param size: number of bytes to be concatenated.
/// @return Total length of the string it tried to create.
size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dest_len)
		return (size + src_len);
	while (src[i] && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
