/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:32:51 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/19 13:33:20 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check_sign(char *str);
char	*ft_delete_whitespace(char *str);
char	*ft_delete_sign(char *str);

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	result = 0;
	str = ft_delete_whitespace(str);
	sign = ft_check_sign(str);
	str = ft_delete_sign(str);
	while (*str)
	{
		if ('0' > *str || *str > '9')
			break ;
		result *= 10;
		if (sign < 0)
			result -= *str - '0';
		else
			result += *str - '0';
		str ++;
	}
	return (result);
}

char	*ft_delete_whitespace(char *str)
{
	while (*str)
	{
		if (*str == '\t' || *str == '\n' || *str == '\v')
			str ++;
		else if (*str == '\f' || *str == '\r' || *str == ' ')
			str ++;
		else
			break ;
	}
	return (str);
}

int	ft_check_sign(char *str)
{
	int	sign;

	sign = 1;
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

char	*ft_delete_sign(char *str)
{
	while (*str)
	{
		if (*str == '-' || *str == '+')
			str ++;
		else
			break ;
	}
	return (str);
}
