/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:09:34 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/15 11:58:55 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	init_functions(int (*funcs[128])(void *))
{
	size_t	i;

	i = 0;
	while (i < 128)
	{
		funcs[i] = NULL;
	}
	funcs['c'] = format_char;
	funcs['s'] = format_str;
	funcs['p'] = format_ptr;
	funcs['d'] = format_int;
	funcs['i'] = format_int;
	funcs['u'] = format_unsigned;
	funcs['x'] = format_hex;
	funcs['X'] = format_upper_hex;
	funcs['%'] = format_percentage;
}

int	parse_command(const char *s)
{
	size_t	i;
	int		(*funcs[128])(void *);

	init_functions(funcs);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (funcs[s[i]])
		}
	}

}

int	ft_printf(char const *s, ...)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')

		i++;
	}
}
