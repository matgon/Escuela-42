/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:01:07 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/10 20:25:28 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief checks whether c is a digit character.
/// @param c: character to be checked.
/// @return 1 true, 0 false
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
