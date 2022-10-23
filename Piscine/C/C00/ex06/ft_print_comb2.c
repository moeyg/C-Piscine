/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:41:02 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/03 10:11:20 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int n);

void	ft_print_comb2(void)
{
	int	num_1;
	int	num_2;

	num_1 = 0;
	while (num_1 <= 98)
	{
		num_2 = num_1 + 1;
		while (num_2 <= 99)
		{
			ft_putchar(num_1 / 10);
			ft_putchar(num_1 % 10);
			write(1, " ", 1);
			ft_putchar(num_2 / 10);
			ft_putchar(num_2 % 10);
			if (!(98 <= num_1 && 99 <= num_2))
				write(1, ", ", 2);
			num_2 ++;
		}
		num_1 ++;
	}
}

void	ft_putchar(int n)
{
	char	num;

	num = n + '0';
	write(1, &num, 1);
}
