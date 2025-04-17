/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:34:40 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/11 12:54:23 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/// @brief Searches for the first character c in s.
/// @param s: first element to be checked.
/// @param c: target character.
/// @return Pointer to the first occurrence of c in s.
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)s + i);
	return (NULL);
}
