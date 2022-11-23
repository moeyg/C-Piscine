/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:14:42 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/19 15:41:05 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *nbr, char *base, int radix);
int		ft_check_base(char *base);
int		ft_divide_integers_by_base(int integer, int radix);
char	*ft_convert_number(int integer, int radix, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	integer;
	int	radix_to;
	int	radix_from;

	radix_from = ft_check_base(base_from);
	radix_to = ft_check_base(base_to);
	if (radix_from < 2 || radix_to < 2)
		return (0);
	integer = ft_atoi_base(nbr, base_from, radix_from);
	return (ft_convert_number(integer, radix_to, base_to));
}

int	ft_check_base(char *base)
{
	char	*cmp;
	int		index;

	index = 0;
	while (base[index])
	{
		cmp = &base[index];
		if (base[index] == '+' || base[index] == '-'
			|| base[index] == '\t' || base[index] == '\n' || base[index] == '\v'
			|| base[index] == '\f' || base[index] == '\r' || base[index] == ' ')
			return (0);
		while (*(cmp++))
		{
			if (*cmp == base[index])
				return (0);
		}
		index ++;
	}
	return (index);
}

char	*ft_convert_number(int integer, int radix, char *base)
{
	char	*numbers;
	int		size;
	int		index;

	numbers = (char *)malloc((sizeof(char) * size + 1));
	size = ft_divide_integers_by_base(integer, radix);
	if (!numbers)
		return (0);
	numbers[size] = '\0';
	if (integer < 0)
	{
		numbers[0] = '-';
		numbers[--size] = base[-(integer % radix)];
		integer = -(integer / radix);
		index = 1;
	}
	else
		index = 0;
	while (index < size)
	{
		numbers[--size] = base[integer % radix];
		integer /= radix;
	}
	return (numbers);
}

int	ft_divide_integers_by_base(int integer, int radix)
{
	int	length;

	length = 1;
	while (integer / radix != 0)
	{
		if (integer < 0)
		{
			integer = -(integer / radix);
			length += 2;
		}
		else
		{
			integer = integer / radix;
			length ++;
		}
	}
	return (length);
}
