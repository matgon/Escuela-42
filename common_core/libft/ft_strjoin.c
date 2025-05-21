/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:50:48 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/11 13:59:27 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Reserva (con malloc(3)) y devuelve una nueva
/// string, formada por la concatenación de ’s1’ y
/// ’s2’.
/// @param s1: La primera string
/// @param s2: La string a aniadir a s1
/// @return La nueva string. Null si falla la reserva de memoria.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, (char *)s1, s1_len + 1);
	ft_strlcpy(ret + s1_len, (char *)s2, s2_len + 1);
	return (ret);
}
