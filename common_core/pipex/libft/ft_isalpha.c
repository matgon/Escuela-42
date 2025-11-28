/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:51:15 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/10 20:26:41 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks wether c is an alphabetic character in uppercase.
/// @param c: character to be checked.
/// @return 1 true, 0 false
int	ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}

/// @brief Checks wether c is an alphabetic character in lowercase.
/// @param c: character to be checked.
/// @return 1 true, 0 false
int	ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}

/// @brief Checks wether c is an alphabetic character.
/// @param c: character to be checked.
/// @return 1 true, 0 false
int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
