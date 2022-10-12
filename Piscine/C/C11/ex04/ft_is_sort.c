/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:17:19 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/19 14:50:52 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	index;
	int	result;

	index = 0;
	while ((index + 1 < length) && (f(tab[index], tab[index + 1]) == 0))
		index ++;
	if (index + 1 < length)
	{
		result = f(tab[index], tab[index + 1]);
		index ++;
	}
	while (index + 1 < length)
	{
		if ((result < 0) && (f(tab[index], tab[index + 1]) > 0))
			return (0);
		else if ((result > 0) && (f(tab[index], tab[index + 1]) < 0))
			return (0);
		index ++;
	}
	return (1);
}
