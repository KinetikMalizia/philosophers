/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:57:07 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/29 15:37:56 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	ft_strlen_nbr(const char *str);
static int	ft_isdigit(int c);

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

int	check_if_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
