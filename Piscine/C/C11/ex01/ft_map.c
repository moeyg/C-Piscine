/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:13:01 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/19 13:40:57 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	index;
	int	*array;

	index = 0;
	array = (int *)malloc(sizeof(int) * length);
	if (array == 0)
		return (0);
	while (index < length)
	{
		array[index] = f(tab[index]);
		index ++;
	}
	return (array);
}
