/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:57:07 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/20 16:30:08 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_strlen_nbr(const char *str);

int	ft_atoi(const char *str)
{
	int	neg;
	int	nb;

	nb = 0;
	neg = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		++str;
	if (*str == '-')
	{
		neg *= -1;
		++str;
	}
	else if (*str == '+')
		++str;
	if (ft_strlen_nbr(str) > 19 && neg < 0)
		return (0);
	if (ft_strlen_nbr(str) > 19 && neg > 0)
		return (-1);
	while ('0' <= *str && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		++str;
	}
	return (nb * neg);
}

static int	ft_strlen_nbr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		++i;
	}
	return (i);
}
/*
int	main(int ac, char **av)
{
	int	i = 1;

	while (i < ac)
	{
		printf("%d\n", atoi(av[i]));
		printf("%d\n", ft_atoi(av[i]));
		++i;
	}
}
*/