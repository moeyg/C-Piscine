/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:26:35 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/19 13:32:08 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H

int		plus(int a, int b);
int		minus(int a, int b);
int		multiply(int a, int b);
int		divide(int a, int b);
int		modulo(int a, int b);

int		ft_atoi(char *str);
int		ft_check_valid_operator(char *operator);
void	ft_putnbr(int nb);

#endif
