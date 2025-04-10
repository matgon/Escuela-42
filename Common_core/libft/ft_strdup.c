/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:58:11 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/10 20:48:38 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Duplicates the string s to another region in memory.
/// @param s: string to be duplicated.
/// @return First element of the duplicated string.
char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*ret;
	char	*aux;

	len = ft_strlen(s);
	ret = (char *) malloc(len * sizeof(char));
	aux = (char *) s;
	i = 0;
	while (aux[i])
	{
		ret[i] = aux[i];
		i++;
	}
	return (ret);
}
