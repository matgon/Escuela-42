/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:09:20 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/15 11:52:54 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct s_mapper
{
	char	c;
	int		*(f)(void *s);
} t_mapper;


int	format_char(void *c);
int	format_str(void *s);
int	format_ptr(void *ptr);
int format_int(void *i);
int	format_unsigned(void *u);
int	format_hex(void *h);
int format_upper_hex(void *h);
int format_percentage(void *per);

int	ft_printf(char const *, ...);