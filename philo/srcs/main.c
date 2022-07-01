/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:45:34 by fmalizia          #+#    #+#             */
/*   Updated: 2022/07/01 16:52:18 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_table	*table;
	t_philo	*ph;

	if (!input_check(ac, av))
		return (0);
	ph = NULL;
	table = set_table(ac, av);
	table->start_time = current_time();
	ph = create_chain(table);
	pthread_create(&(table->death), NULL, &death_monitor, (void *)table);
	pthread_join(table->death, NULL);
	kill_philos(ph);
	clean_table(table);
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
	if (!check_if_digit(ac, &av[1]))
	{
		printf("Digit Error\n");
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
	printf("join start\n");
	while (i <= max)
	{
		pthread_join(current->philosopher, NULL);
		printf("%d joined", current->philo_id);
		i++;
		current = current->next;
	}
}

void	print_meals(t_philo *phil)
{
	t_philo	*current;
	int		i;
	int		max;

	current = phil;
	i = 1;
	max = phil->table->philos_num;
	while (i <= max)
	{
		printf("philo %d has eaten %d meals\n", current->philo_id,
			current->num_meals);
		i++;
		current = current->next;
	}
}
