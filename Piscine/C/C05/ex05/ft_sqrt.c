/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:42:47 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/12 21:43:34 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	root;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	root = 0;
	while (root <= nb && root <= 46341)
	{
		if (root * root == nb)
			return (root);
		root ++;
	}
	return (0);
}
