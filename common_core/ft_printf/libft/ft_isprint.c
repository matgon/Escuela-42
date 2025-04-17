/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:59:01 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/11 12:30:41 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks wether c is an space separator character 
///			(' ', '\t', '\n', '\v', '\f', '\r').
/// @param c: character to be checked.
/// @return 1 true, 0 false
int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

/// @brief Checks wether c is a printable character.
/// @param c: character to be checked.
/// @return 1 true, 0 false
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
