/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:09:34 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/18 17:10:53 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_char(va_list *arg)
{
	char	c;

	c = (char) va_arg(*arg, int);
	return ((int) write(1, &c, sizeof(char)));
}

int	format_str(va_list *arg)
{
	int		ret;
	ssize_t	n_bytes;
	char	*str;

	ret = 0;
	str = (char *) va_arg(*arg, char *);
	if (!str)
		ret = write(1, "(null)", sizeof(char) * 6);
	while (*str)
	{
		n_bytes = write(1, str++, sizeof(char));
		if (n_bytes == -1)
			return (-1);
		ret += n_bytes;
	}
	return (ret);
}

int	format_ptr(va_list *arg)
{
	char			hex_address[16];
	unsigned long	address;
	int				i;
	int				total;
	const char		g_hex_digits[16] = "0123456789abcdef";

	address = va_arg(*arg, unsigned long);
	i = 15;
	total = 0;
	while (i >= 0)
	{
			hex_address[i] = g_hex_digits[address & 0xF];
			address >>= 4;
			i--;
			total++;
	}
	i = 0;
	while (i < 16 && hex_address[i] == '0')
		i++;
	write(1, "0x", sizeof(char) * 2);
	write(1, &hex_address[i], 16-i);
	return (16 - i + 2);
}

int	format_int(va_list *arg)
{
	int		n;
	char	*str;

	n = va_arg(*arg, int);
	str = ft_itoa(n);
	ft_putstr_fd(str, 1);
	free(str);
	return (ft_num_digits(n));
}

int	ft_put_unsigned(unsigned int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n >= 10)
		count += ft_put_unsigned(n / 10);
	digit = '0' + (n % 10);
	count += write(1, &digit, 1);
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
	unsigned int		num;
	char				buffer[8];
	char				*hex_digits = "0123456789abcdef";
	int					i = 8;
	int					count = 0;

	num = va_arg(*arg, unsigned int);
	if (num == 0)
		return (write(1, "0", 1));

	while (num > 0 && i > 0)
	{
		buffer[--i] = hex_digits[num & 0xF];
		num >>= 4;
	}
	while (i < 8)
		count += write(1, &buffer[i++], 1);
	return (count);
}

int	format_upper_hex(va_list *arg)
{
	unsigned int		num;
	char				buffer[8];
	char				*hex_digits = "0123456789ABCDEF";
	int					i = 8;
	int					count = 0;

	num = va_arg(*arg, unsigned int);
	if (num == 0)
		return (write(1, "0", 1));

	while (num > 0 && i > 0)
	{
		buffer[--i] = hex_digits[num & 0xF];
		num >>= 4;
	}
	while (i < 8)
		count += write(1, &buffer[i++], 1);
	return (count);
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
			n_bytes = funcs[(int) s[i++ + 1]](&args);
		else
			n_bytes = write(1, &s[i], sizeof(char));
		if (n_bytes == -1)
			return (end(-1, &args));
		total += n_bytes;
		i++;
	}
	return (end(total, &args));
}

// int main()
// {
// 	printf("primero: %x, despues: %X\n", 0, 0);
// 	printf("primero: %x, despues: %X", 0, 0);
// }