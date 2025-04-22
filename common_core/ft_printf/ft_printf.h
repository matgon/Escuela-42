/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:09:20 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/18 14:49:46 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

int	format_char(va_list *arg);
int	format_str(va_list *arg);
int	format_ptr(va_list *arg);
int	format_int(va_list *arg);
int	format_unsigned(va_list *arg);
int	format_hex(va_list *h);
int	format_upper_hex(va_list *h);
int	format_percentage(va_list *per);

int	ft_printf(char const *, ...);