/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:33:30 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/19 13:33:31 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	plus(int a, int b)
{
	return (a + b);
}

int	minus(int a, int b)
{
	return (a - b);
}

int	multiply(int a, int b)
{
	return (a * b);
}

int	divide(int a, int b)
{
	if (b == 0)
		return (0);
	return (a / b);
}

int	modulo(int a, int b)
{
	if (b == 0)
		return (0);
	return (a % b);
}
