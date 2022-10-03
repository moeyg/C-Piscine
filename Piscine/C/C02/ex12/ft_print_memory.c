/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:55:00 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/10 16:13:31 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_addr_to_hex(long unsigned int addr);
void	ft_print_char_to_hex(char *str, unsigned int size);
void	ft_putstr(char *str, unsigned int size);

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		index;

	index = (size / 16) + 1;
	while (index > 0)
	{
		ft_print_addr_to_hex((long unsigned int) addr);
		ft_print_char_to_hex(addr, size);
		ft_putstr(addr, size);
		addr = addr + 16;
		size = size - 16;
		index --;
	}
	return (addr);
}

void	ft_print_addr_to_hex(long unsigned int addr)
{
	char	*hex;
	int		string[16];
	int		index;

	index = -1;
	hex = "0123456789abcdef";
	while (++index < 16)
	{
		string[index] = addr % 16;
		addr /= 16;
	}
	while (--index >= 0)
	{
		write(1, &hex[string[index]], 1);
	}
	write(1, ": ", 2);
}

void	ft_print_char_to_hex(char *str, unsigned int size)
{
	int		index;
	char	*hex;

	index = 0;
	hex = "0123456789abcdef";
	while (index < 16 && size-- > 0)
	{
		write(1, &hex[((unsigned char)str[index] / 16)], 1);
		write(1, &hex[((unsigned char)str[index] % 16)], 1);
		if ((index + 1) % 2 == 0)
			write(1, " ", 1);
		index++;
	}
	while (index < 16)
	{
		write(1, "  ", 2);
		if ((index + 1) % 2 == 0)
			write(1, " ", 1);
		index ++;
	}
}

void	ft_putstr(char *str, unsigned int size)
{
	int	index;

	index = 0;
	while (index < 16 && size - index > 0)
	{
		if (str[index] < 32 || str[index] > 126)
			write(1, ".", 1);
		else
			write(1, &str[index], 1);
		index ++;
	}
	write(1, "\n", 1);
}
