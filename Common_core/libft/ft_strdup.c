/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:58:11 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/11 12:44:34 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Duplicates the string s to another region in memory.
/// @param s: string to be duplicated.
/// @return First element of the duplicated string.
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ret;
	char	*aux;

	len = ft_strlen(s);
	ret = (char *) malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	aux = (char *) s;
	ft_strlcpy(ret, aux, len + 1);
	return (ret);
}
