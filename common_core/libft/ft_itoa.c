/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:30:34 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/18 14:15:20 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_digits(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	else
	{
		while (n != 0)
		{
			n /= 10;
			digits++;
		}
		return (digits);
	}
}

static void	init_vars(int n, unsigned int *digits, unsigned int *sign)
{
	*digits = (unsigned int) ft_num_digits(n);
	*sign = 0;
	if (n < 0)
		*sign = 1;
}

static void	loop(int n, char *ret, unsigned int digits, unsigned int sign)
{
	while (n != 0)
	{
		if (n > 0)
			ret[digits--] = (n % 10) + '0';
		else
			ret[sign + digits--] = (-(n % 10)) + '0';
		n /= 10;
	}
}

/// @brief Utilizando malloc(3), genera una string que
/// represente el valor entero recibido como argumento.
/// Los números negativos tienen que gestionarse.
/// @param n: el entero a convertir.
/// @return La string que represente el número.
/// NULL si falla la reserva de memoria.
char	*ft_itoa(int n)
{
	char			*ret;
	unsigned int	digits;
	unsigned int	sign;

	init_vars(n, &digits, &sign);
	ret = (char *) malloc((digits + 1 + sign) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[digits + sign] = '\0';
	if (!ret)
		return (NULL);
	digits = digits - 1;
	if (n == 0)
		ret[sign + digits] = '0';
	else
	{
		loop(n, ret, digits, sign);
	}
	if (sign)
		ret[0] = '-';
	return (ret);
}
