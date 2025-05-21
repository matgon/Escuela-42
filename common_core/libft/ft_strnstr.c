/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:26:23 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/10 20:56:49 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Locates the first occurrence of the  null terminated string 
///			little in the string big, where not more than len characters
///			 are searched.
/// @param big: string where little will be searched.
/// @param little: substring to be searched.
/// @param len: number of bytes to be searched.
/// @return Pointer to the first occurrence of little in big.
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	char	*str;

	str = (char *) big;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return (str);
	i = 0;
	while (big[i] && i + little_len <= len)
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(big + i, little, little_len) == 0)
				return (str + i);
		}
		i++;
	}
	return (NULL);
}
