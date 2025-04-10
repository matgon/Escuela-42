/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:51:15 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/09 12:07:27 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}

int	ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
