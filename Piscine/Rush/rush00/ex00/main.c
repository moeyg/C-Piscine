/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:06:15 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/02 19:23:08 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	ft_atoi(char *str)
{
	int			index;
	long long	number;

	index = 0;
	number = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= '0' && str[index] <= '9')
		{
			number = number * 10 + str[index] - '0';
			if (number > 2147483647)
				return (0);
		}
		else
			return (0);
		index ++;
	}
	return (number);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc != 3)
		return (0);
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	rush(x, y);
	return (0);
}
