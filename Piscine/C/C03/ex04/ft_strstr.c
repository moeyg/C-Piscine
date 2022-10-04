/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:08:21 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/06 01:29:58 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	index;

	if (*to_find == '\0')
	{
		return (str);
	}
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			index = 0;
			while (to_find[index] != '\0' && str[index] == to_find[index])
				index ++;
			if (to_find[index] == '\0')
				return (str);
		}
		str ++;
	}
	return (0);
}
