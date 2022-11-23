/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:10:31 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/19 15:39:05 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_number(char nbr, char *base);

int	ft_atoi_base(char *nbr, char *base, int radix)
{
	int	sign;
	int	number;
	int	result;

	if (radix < 2)
		return (0);
	sign = 1;
	result = 0;
	while (*nbr == '\t' || *nbr == '\n' || *nbr == '\v'
		|| *nbr == '\f' || *nbr == '\r' || *nbr == ' ')
		nbr ++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*(nbr)++ == '-')
			sign = -sign;
	}
	while (*nbr)
	{
		number = ft_check_number(*nbr, base);
		if (number < 0)
			break ;
		result = (result * radix) + (sign * number);
		nbr ++;
	}
	return (result);
}

int	ft_check_number(char nbr, char *base)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (nbr == base[index])
			return (index);
		index ++;
	}
	return (-1);
}
