/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:39:42 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/13 01:07:29 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(char *base);
int	ft_check_sign(char *str);
int	ft_print_numbers(char str, char *base);
char	*ft_putstr(char *str);

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	radix;
	int	sign;
	int	number;

	result = 0;
	radix = ft_check_base(base);
	sign = ft_check_sign(str);
	str = ft_putstr(str);
	if (radix < 2)
		return (0);
	while (*str)
	{
		number = ft_print_numbers(*str, base);
		if (number == -1)
			break ;
		result *= radix;
		result += sign * number;
		str ++;
	}
	return (result);
}

int	ft_check_base(char *base)
{
	int	radix;
	int	index;

	radix = 0;
	while (base[radix] != '\0')
	{
		index = 0;
		if (base[radix] == '-' || base[radix] == '+')
			return (-1);
		if (base[radix] == '\t' || base[radix] == '\n' || base[radix] == '\v')
			return (-1);
		if (base[radix] == '\f' || base[radix] == '\r' || base[radix] == ' ')
			return (-1);
		while (index < radix)
		{
			if (base[index] == base[radix])
				return (-1);
			index++;
		}
		radix++;
	}
	if (radix < 2)
		return (-1);
	return (radix);
}

int	ft_check_sign(char *str)
{
	int	sign;

	sign = 1;
	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\f' || *str == '\r' || *str == '\v')
			str ++;
		else
			break ;
	}
	while (*str)
	{
		if (*str == '-')
			sign = -sign;
		else if (*str == '+')
			;
		else
			break ;
		str ++;
	}
	return (sign);
}

char	*ft_putstr(char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\f' || *str == '\r' || *str == '\v')
			str ++;
		else
			break ;
	}
	while (*str)
	{
		if (*str == '-' || *str == '+')
			str ++;
		else
			break ;
	}
	return (str);
}

int	ft_print_numbers(char str, char *base)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (str == base[index])
			return (index);
		index ++;
	}
	return (-1);
}
