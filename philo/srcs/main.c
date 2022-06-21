/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:45:34 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/21 15:49:13 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_table	*table;
	t_philo	**ph;

	if (!input_check(ac, av))
		return (0);
	printf("table\n");
	table = set_table(ac, av);
	printf("chain\n");
	*ph = create_chain(*table);
}

int	input_check(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		printf("Argument Error\n");
		return (0);
	}
	return (1);
}
