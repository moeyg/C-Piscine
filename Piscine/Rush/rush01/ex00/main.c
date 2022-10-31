/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:00:36 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/09 20:47:08 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		prom_input(char *str, int *temp_input);
void	print_error(void);
void	dfs(int y, int x, int (*res_arr)[6]);
void	make_board(int (*res_arr)[6], int *temp_input);
int		prom_col(int y, int x, int (*res_arr)[6]);
int		prom_row(int y, int x, int (*res_arr)[6]);
int		prom_col_rev(int y, int x, int (*res_arr)[6]);
int		prom_row_rev(int y, int x, int (*res_arr)[6]);
void	print_board(int (*res_arr)[6]);

int	main(int argc, char **argv)
{
	int	res_arr[6][6];
	int	temp_input[16];

	if (argc != 2)
		print_error();
	if (prom_input(argv[1], temp_input))
	{
		make_board(res_arr, temp_input);
		dfs(1, 1, res_arr);
	}
	print_error();
}

int	prom_input(char *str, int *temp_input)
{
	int	index;

	index = -1;
	while (str[++index] != '\0')
	{
		if (index % 2 == 0)
		{
			if (!(str[index] >= '1' && str[index] <= '4'))
				print_error();
			temp_input[index / 2] = str[index] - '0';
		}
		else if (str[index] != ' ')
			print_error();
	}
	if (index != 31)
		print_error();
	return (1);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
