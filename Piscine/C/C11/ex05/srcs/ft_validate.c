/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:33:41 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/19 13:33:45 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_operator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '/'
		|| ch == '*' || ch == '%')
		return (1);
	return (0);
}

int	ft_check_valid_operator(char *operator)
{
	int	index;

	index = 0;
	while (operator[index])
		index ++;
	if (index != 1)
		return (0);
	if (!ft_check_operator(operator[0]))
		return (0);
	return (1);
}
