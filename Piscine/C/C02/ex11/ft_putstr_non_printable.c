/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:11:23 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/05 23:25:34 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr_non_printable(char *str)
{
	char			*hex;
	unsigned char	string;
	int				index;

	hex = "0123456789abcdef";
	index = 0;
	while (str[index] != '\0')
	{
		string = str[index];
		if (str[index] > 31 && str[index] < 127)
			ft_putchar(str[index]);
		else
		{
			ft_putchar('\\');
			ft_putchar(hex[string / 16]);
			ft_putchar(hex[string % 16]);
		}
		index ++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
