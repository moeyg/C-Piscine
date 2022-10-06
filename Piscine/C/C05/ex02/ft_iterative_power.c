/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:39:30 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/13 06:08:06 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	exponent;
	int	base;

	exponent = 1;
	base = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (exponent < power)
	{
		nb = nb * base;
		exponent ++;
	}
	return (nb);
}
