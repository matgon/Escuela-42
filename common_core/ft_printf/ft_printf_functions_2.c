/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:58:30 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/26 20:52:08 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_ptr(va_list *arg)
{
	const char		g_hex_digits[16] = "0123456789abcdef";
	char			hex_address[18];
	unsigned long	address;
	int				i;

	address = va_arg(*arg, unsigned long);
	if (!address)
		return (write_str("(nil)", 5));
	ft_bzero(hex_address, 18);
	ft_memmove(hex_address, "0x", 2);
	i = 17;
	while (i >= 2)
	{
		hex_address[i] = g_hex_digits[address & 0xF];
		address >>= 4;
		i--;
	}
	i = 2;
	while (i < 18 && hex_address[i] == '0')
		i++;
	ft_memmove(&hex_address[2], &hex_address[i], 18 - (i - 2));
	return (write_str(hex_address, 18 - (i - 2)));
}

int	format_hex(va_list *arg)
{
	const char			*hex_digits = "0123456789abcdef";
	unsigned int		num;
	char				buffer[8];
	int					i;
	int					digits;

	i = 8;
	digits = 0;
	num = va_arg(*arg, unsigned int);
	if (num == 0)
		return (write(1, "0", 1));
	while (num > 0 && i > 0)
	{
		buffer[--i] = hex_digits[num & 0xF];
		num >>= 4;
		digits++;
	}
	return (write_str(&buffer[8 - digits], digits));
}

int	format_upper_hex(va_list *arg)
{
	const char			*hex_digits = "0123456789ABCDEF";
	unsigned int		num;
	char				buffer[8];
	int					i;
	int					digits;

	i = 8;
	digits = 0;
	num = va_arg(*arg, unsigned int);
	if (num == 0)
		return (write(1, "0", 1));
	while (num > 0 && i > 0)
	{
		buffer[--i] = hex_digits[num & 0xF];
		num >>= 4;
		digits++;
	}
	return (write_str(&buffer[8 - digits], digits));
}
