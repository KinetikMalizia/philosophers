/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:45:34 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/23 15:35:33 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_table	*table;
	t_philo	**ph;

	if (!input_check(ac, av))
		return (0);
	ph = malloc(sizeof(t_philo *));
	table = set_table(ac, av);
	*ph = create_chain(table);
	pthread_join((*ph)->philosopher, NULL);
	join(*ph);
	//print_phi(*ph);
}

int	input_check(int ac, char **av)
{
	int	i;

	i = 1;
	(void)av;
	if (ac < 5 || ac > 6)
	{
		printf("Argument Error\n");
		return (0);
	}
	return (1);
}

void	join(t_philo *phil)
{
	t_philo	*current;
	int		i;
	int		max;

	current = phil;
	i = 1;
	max = phil->table->philos_num;
	while (i <= max)
	{
		pthread_join(current->philosopher, NULL);
		i++;
		current = current->next;
	}
}
