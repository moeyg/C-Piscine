/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:19:36 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/13 03:53:01 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);
int	ft_check_base(char *base, int radix);
void	ft_print_numbers(int nbr, char *base, int radix);

void	ft_putnbr_base(int nbr, char *base)
{
	int	radix;

	radix = ft_strlen(base);
	if (ft_check_base(base, radix))
		ft_print_numbers(nbr, base, radix);
}

int	ft_strlen(char *base)
{
	int	length;

	length = 0;
	while (base[length])
		length ++;
	return (length);
}

int	ft_check_base(char *base, int radix)
{
	char	*temp;

	if (radix < 2)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		temp = base + 1;
		while (*temp)
		{
			if (*temp == *base)
				return (0);
			temp ++;
		}
		base ++;
	}
	return (1);
}

void	ft_print_numbers(int nbr, char *base, int radix)
{
	long long	number;

	if (nbr < 0)
	{
		write(1, "-", 1);
		number = -(nbr % radix);
		if (nbr / radix != 0)
			ft_print_numbers(-(nbr / radix), base, radix);
	}
	else if (nbr / radix == 0)
		number = nbr;
	else
	{
		number = nbr % radix;
		ft_print_numbers(nbr / radix, base, radix);
	}
	write(1, &base[number], 1);
}
