/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:34:00 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/19 13:34:33 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "doop.h"

int		ft_operater(int a, char operator, int b);
void	ft_putnbr(int nb);

int	main(int argc, char *argv[])
{
	int		a;
	int		b;
	char	operator;

	if (argc == 4)
	{	
		if (!ft_check_valid_operator(argv[2]))
			write(1, "0\n", 2);
		else
		{
			a = ft_atoi(argv[1]);
			operator = *argv[2];
			b = ft_atoi(argv[3]);
			if (operator == '/' && b == 0)
				write(1, "Stop : division by zero\n", 24);
			else if (operator == '%' && b == 0)
				write(1, "Stop : modulo by zero\n", 22);
			else
			{
				ft_putnbr(ft_operater(a, operator, b));
				write(1, "\n", 1);
			}
		}
	}
}

int	ft_operater(int a, char operator, int b)
{
	int	(*op[5])(int, int);

	op[0] = &plus;
	op[1] = &minus;
	op[2] = &multiply;
	op[3] = &divide;
	op[4] = &modulo;
	if (operator == '+')
		return (op[0](a, b));
	if (operator == '-')
		return (op[1](a, b));
	if (operator == '*')
		return (op[2](a, b));
	if (operator == '/')
		return (op[3](a, b));
	if (operator == '%')
		return (op[4](a, b));
	return (0);
}

void	ft_putnbr(int nb)
{
	char	number;

	if (nb < 0)
	{
		write(1, "-", 1);
		number = -(nb % 10) + '0';
		if (nb / 10 != 0)
			ft_putnbr(-(nb / 10));
	}
	else if (nb / 10 == 0)
	{
		number = nb + '0';
	}
	else
	{
		number = (nb % 10) + '0';
		ft_putnbr(nb / 10);
	}
	write(1, &number, 1);
}
