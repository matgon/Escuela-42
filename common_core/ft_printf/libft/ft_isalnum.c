/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:15:51 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/10 20:27:08 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks wether c is an alphanumeric character.
/// @param c: character to be checked.
/// @return 1 true, 0 false
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
