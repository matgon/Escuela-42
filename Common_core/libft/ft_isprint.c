/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:59:01 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/10 20:27:33 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks wether c is a printable character.
/// @param c: character to be checked.
/// @return 1 true, 0 false
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
