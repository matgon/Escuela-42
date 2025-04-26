/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:09:34 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/26 18:28:44 by matgonza         ###   ########.fr       */
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

int	format_char(va_list *arg)
{
	char	c;

	c = (char) va_arg(*arg, int);
	return (write_char(c));
}

int	format_str(va_list *arg)
{
	char	*str;

	str = (char *) va_arg(*arg, char *);
	if (!str)
		return (write_str("(null)", 6));
	return (write_str(str, (int) ft_strlen(str)));
}

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
	ft_memmove(&hex_address[2], &hex_address[i], 18 - (i-2));
	return (write_str(hex_address, 18 - (i - 2)));
}

int	format_int(va_list *arg)
{
	int		n;
	char	*str;

	n = va_arg(*arg, int);
	str = ft_itoa(n);
	n = write_str(str, ft_strlen(str));
	free(str);
	return (n);
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

int	format_unsigned(va_list *arg)
{
	unsigned int	n;

	n = va_arg(*arg, unsigned int);
	return (ft_put_unsigned(n));
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

int	format_percentage(va_list *arg)
{
	(void)arg;
	return (write(1, "%", sizeof(char)));
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

int	end(int code, va_list *args)
{
	va_end(*args);
	return (code);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		total;
	int		n_bytes;
	va_list	args;
	int		(*funcs[128])(va_list *);

	i = 0;
	total = 0;
	init_functions(funcs);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && funcs[(int) s[i + 1]])
		{
			n_bytes = funcs[(int) s[i++ + 1]](&args);
			write(1, (char[]){'0' + n_bytes}, 1);
		}
		else
			n_bytes = write(1, &s[i], sizeof(char));
		if (n_bytes == -1)
			return (end(-1, &args));
		total += n_bytes;
		i++;
	}
	return (end(total, &args));
}

int main()
{
	int n;

	n = 5;
	// printf("primero: %u\n", 120);
	n = ft_printf("primero: %u\n", 120);
	//ft_printf("%d", n);
}
