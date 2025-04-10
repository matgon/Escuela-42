/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:29:06 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/10 20:58:22 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Converts the character c to uppercase.
/// @param c: char to be converted.
/// @return Converted character.
int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return c;
}
