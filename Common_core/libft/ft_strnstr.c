/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:26:23 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/09 15:27:37 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
