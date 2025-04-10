/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:58:11 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/09 17:58:48 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
