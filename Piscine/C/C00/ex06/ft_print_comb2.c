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
	int	front_num;
	int	back_num;

	front_num = 0;
	while (front_num <= 98)
	{
		back_num = front_num + 1;
		while (back_num <= 99)
		{
			ft_putchar(front_num / 10);
			ft_putchar(front_num % 10);
			write(1, " ", 1);
			ft_putchar(back_num / 10);
			ft_putchar(back_num % 10);
			if (!(98 <= front_num && 99 <= back_num))
				write(1, ", ", 2);
			back_num ++;
		}
		front_num ++;
	}
}

void	ft_putchar(int num)
{
	char	number;

	number = num + '0';
	write(1, &number, 1);
}
