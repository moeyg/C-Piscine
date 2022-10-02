/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:43:30 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/03 10:57:46 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	begin;
	int	end;
	int	temp;

	begin = 0;
	end = size - 1;
	while (begin < size / 2)
	{
		temp = tab[begin];
		tab[begin] = tab[end];
		tab[end] = temp;
		begin ++;
		end --;
	}
}
