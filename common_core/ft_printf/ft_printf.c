/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:09:34 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/26 20:14:43 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
