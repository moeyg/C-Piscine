/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:51:11 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/05 16:57:00 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_str_upcase(char *str);

char	*ft_strcapitalize(char *str)
{
	int	index;

	ft_str_upcase(str);
	index = 1;
	while (str[index] != '\0')
	{
		if ((str[index] >= 'A' && str[index] <= 'Z')
			&& ((str[index - 1] >= 'a' && str[index - 1] <= 'z')
				|| (str[index - 1] >= 'A' && str[index - 1] <= 'Z')
				|| (str[index - 1] >= '0' && str[index - 1] <= '9')))
		{
			str[index] = str[index] + 32;
		}
		index ++;
	}
	return (str);
}

char	*ft_str_upcase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 'a' && str[index] <= 'z')
		{
			str[index] = str[index] - 32;
		}
		index ++;
	}
	return (str);
}
