/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:01:27 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/26 20:51:51 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(char c)
{
	return (write(1, &c, sizeof(char)));
}

int	write_str(char *str, ssize_t length)
{
	ssize_t	i;

	i = 0;
	while (i < length && str[i])
	{
		if (write_char(str[i++]) == -1)
			return (-1);
	}
	return (length);
}

int	ft_put_unsigned(unsigned int n)
{
	int		count;
	int		ret;

	ret = 0;
	count = 0;
	if (n >= 10)
	{
		ret = ft_put_unsigned(n / 10);
		if (ret == -1)
			return (ret);
		count += ret;
		ret = write_char('0' + (n % 10));
		if (ret == -1)
			return (ret);
		count += ret;
	}
	else
	{
		ret = write_char('0' + (n % 10));
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return (count);
}

int	end(int code, va_list *args)
{
	va_end(*args);
	return (code);
}

void	init_functions(int (*funcs[128])(va_list *))
{
	size_t	i;

	i = 0;
	while (i < 128)
	{
		funcs[i++] = NULL;
	}
	funcs['c'] = format_char;
	funcs['s'] = format_str;
	funcs['p'] = format_ptr;
	funcs['i'] = format_int;
	funcs['d'] = format_int;
	funcs['u'] = format_unsigned;
	funcs['x'] = format_hex;
	funcs['X'] = format_upper_hex;
	funcs['%'] = format_percentage;
}
