/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:58:34 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/26 20:34:19 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	format_unsigned(va_list *arg)
{
	unsigned int	n;

	n = va_arg(*arg, unsigned int);
	return (ft_put_unsigned(n));
}

int	format_percentage(va_list *arg)
{
	(void)arg;
	return (write(1, "%", sizeof(char)));
}
