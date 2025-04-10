/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgon <matgon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:16:38 by matgon            #+#    #+#             */
/*   Updated: 2025/02/25 21:32:36 by matgon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char	g_hex_digits[16] = "0123456789abcdef";

void	write_chars(char *str, unsigned int remaining_size)
{
	int	i;

	i = 0;
	while (i < 16 && str[i] && i < remaining_size)
	{
		if (str[i] >= 0 && str[i] <= 31)
			write(1, ".", sizeof(char));
		else
			write(1, &str[i], sizeof(char));
		i++;
	}
}

void	write_chars_to_hex(char *c, unsigned int remaining_size)
{
	int		i;
	char	hex[2];
	int		spaces;

	i = 0;
	spaces = 0;
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", sizeof(char));
		if (!spaces && c[i] && i < remaining_size)
		{
			hex[0] = g_hex_digits[(c[i] >> 4) & 0xF];
			hex[1] = g_hex_digits[c[i] & 0xF];
			write(1, &hex[0], 1);
			write(1, &hex[1], 1);
		}
		else
		{
			spaces = 1;
			write(1, "  ", sizeof(char) * 2);
		}
		i++;
	}
	write(1, " ", sizeof(char));
}

void	write_addr(void *addr)
{
	char			hex_address[16];
	unsigned long	address;
	int				i;

	address = (unsigned long)addr;
	i = 15;
	while (i >= 0)
	{
		hex_address[i] = g_hex_digits[address & 0xF];
		address >>= 4;
		i--;
	}
	write(1, hex_address, 16);
	write(1, ":", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	remaining_size;
	char			*char_addr;

	char_addr = (char *) addr;
	i = 0;
	remaining_size = size;
	while (i < size)
	{
		write_addr(&char_addr[i]);
		write_chars_to_hex(&char_addr[i], remaining_size);
		write_chars(&char_addr[i], remaining_size);
		write(1, "\n", sizeof(char));
		i += 16;
		remaining_size -= 16;
	}
	return (addr);
}

int main() {
    char str[36] = "Bonjour les aminches...c\n est fou\ntout\nce qu on peut faire avec\n..print_memory....lol.lol. \n";
    void *addre = &str;

    ft_print_memory(addre, 36);

    return (0);
}
