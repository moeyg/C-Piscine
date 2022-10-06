/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:46:10 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/16 00:36:03 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	dfs(char *chessboard, int column);
int	check_valid(char *chessboard, int column);

int	ft_ten_queens_puzzle(void)
{
	int		count;
	char	chessboard[10];

	count = 0;
	count += dfs(chessboard, 0);
	return (count);
}

int	dfs(char *chessboard, int column)
{
	int	index;
	int	count;

	count = 0;
	if (column == 10)
	{
		write(1, chessboard, 10);
		write(1, "\n", 1);
		count++;
	}
	else
	{
		index = 0;
		while (index < 10)
		{
			chessboard[column] = index + '0';
			if (check_valid(chessboard, column))
				count += dfs(chessboard, column + 1);
			index ++;
		}
	}
	return (count);
}

int	check_valid(char *chessboard, int column)
{
	int	index;

	index = 0;
	while (index < column)
	{
		if (chessboard[index] == chessboard[column])
			return (0);
		if (column - index == chessboard[column] - chessboard[index])
			return (0);
		if (column - index == chessboard[index] - chessboard[column])
			return (0);
		index ++;
	}
	return (1);
}
