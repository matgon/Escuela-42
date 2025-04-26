/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:09:20 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/26 20:32:54 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

int		write_char(char c);
int		write_str(char *str, ssize_t length);
int		ft_put_unsigned(unsigned int n);
int		end(int code, va_list *args);
void	init_functions(int (*funcs[128])(va_list *));

int		format_char(va_list *arg);
int		format_str(va_list *arg);
int		format_int(va_list *arg);
int		format_unsigned(va_list *arg);
int		format_percentage(va_list *per);

int		format_ptr(va_list *arg);
int		format_hex(va_list *h);
int		format_upper_hex(va_list *h);

int		ft_printf(char const *s, ...);

#endif
