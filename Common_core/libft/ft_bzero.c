/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:23:45 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/10 20:21:18 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Initializes the first n elements of s to 0.
/// @param s: pointer to the first element.
/// @param n: number of elements to initialize.
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
