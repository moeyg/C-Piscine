/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:54:29 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/02 18:41:13 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(char begin, char mid, char end, int x)
{
	int	index;

	index = 2;
	ft_putchar(begin);
	while (index < x)
	{
		ft_putchar(mid);
		index++;
	}
	if (index == x)
		ft_putchar(end);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	index;

	index = 2;
	if (x <= 0 || y <= 0)
		return ;
	ft_print_line('A', 'B', 'C', x);
	while (index < y)
	{
		ft_print_line('B', ' ', 'B', x);
		index++;
	}
	if (index == y)
		ft_print_line('C', 'B', 'A', x);
}
