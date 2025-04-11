/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:44:15 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/10 22:07:13 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief checks whether c is a 7-bit unsigned char 
///			value that fits into the ASCII character set.
/// @param c: character to be checked.
/// @return 1 true, 0 false
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
