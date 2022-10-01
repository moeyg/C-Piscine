/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:40:24 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/03 10:14:27 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(char num[], char first_digit, int index, int n);

void	ft_print_combn(int n)
{
	char	num[10];
	char	first_digit;
	int	index;

	first_digit = '0';
	index = 1;
	while (first_digit <= '9')
	{
		num[0] = first_digit;
		ft_print_numbers(num, first_digit, index, n);
		first_digit ++;
	}
}

void	ft_print_numbers(char num[], char first_digit, int index, int n)
{
	if (index == n)
	{
		write(1, num, n);
		if (num[0] != 10 - n + '0')
			write(1, ", ", 2);
		return ;
	}
	first_digit = first_digit + 1;
	while (first_digit <= '9')
	{
		num[index] = first_digit;
		ft_print_numbers(num, first_digit, index + 1, n);
		first_digit ++;
	}
}
