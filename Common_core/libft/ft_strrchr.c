/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:02:52 by matgon            #+#    #+#             */
/*   Updated: 2025/04/10 20:57:26 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Searches for the last character c in s.
/// @param s: first element to be checked.
/// @param c: target character.
/// @return Pointer to the last occurrence of c in s.
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	pos;

	i = 0;
	pos = 0;
	while (s[i])
	{
		if (s[i] == c)
			pos = i;
		i++;
	}
	if (c == '\0' && s[i] == '\0')
		return ((char *) (s + i));
	else if (pos >= 0 && s[pos] == c)
		return ((char *) (s + pos));
	return (NULL);
}
