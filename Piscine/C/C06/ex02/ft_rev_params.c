/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:43:24 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/13 03:50:19 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	index;

	index = argc - 1;
	while (index > 0)
	{
		while (*argv[index] != '\0')
		{
			write(1, argv[index], 1);
			argv[index]++;
		}
		write(1, "\n", 1);
		index --;
	}
}
