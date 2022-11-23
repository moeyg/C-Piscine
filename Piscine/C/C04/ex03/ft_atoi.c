/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:29:00 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/13 01:05:14 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_sign(char *str);
char	*ft_delete_whitespace(char *str);
char	*ft_putstr(char	*str);

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	str = ft_delete_whitespace(str);
	sign = ft_check_sign(str);
	str = ft_putstr(str);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			break ;
		result = result * 10;
		if (sign < 0)
			result = result - (*str - '0');
		else
			result = result + (*str - '0');
		str ++;
	}
	return (result);
}

char	*ft_delete_whitespace(char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\f' || *str == '\r' || *str == '\v')
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

char	*ft_putstr(char *str)
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
