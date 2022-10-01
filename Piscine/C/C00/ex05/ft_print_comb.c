/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:47:05 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/02 22:19:56 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	hundreds;
	char	tens;
	char	units;

	hundreds = '0';
	while (hundreds <= '7')
	{
		tens = hundreds + 1;
		while (tens <= '8')
		{
			units = tens + 1;
			while (units <= '9')
			{
				write(1, &hundreds, 1);
				write(1, &tens, 1);
				write(1, &units, 1);
				if (hundreds != '7')
					write(1, ", ", 2);
				units ++;
			}
			tens ++;
		}
		hundreds ++;
	}
}
