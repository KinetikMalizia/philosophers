/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:50:57 by fmalizia          #+#    #+#             */
/*   Updated: 2022/07/01 16:52:12 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_philo	*add_philosopher(int id)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	new->philo_id = id;
	new->last_meal = 0;
	new->num_meals = 0;
	return (new);
}

t_table	*set_table(int ac, char **av)
{
	t_table	*tab;

	tab = malloc(sizeof(t_table));
	tab->philos_num = ft_atoi(av[1]);
	tab->time_to_die = ft_atoi(av[2]);
	tab->time_to_eat = ft_atoi(av[3]);
	tab->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		tab->eat_num = ft_atoi(av[5]);
	else
		tab->eat_num = -1;
	tab->someonedied = FALSE;
	tab->forks = malloc(sizeof(pthread_mutex_t) * (tab->philos_num + 1));
	if (pthread_mutex_init(&tab->print_locker, NULL))
		printf("mutex init failed\n");
	make_forks(tab);
	tab->head = NULL;
	return (tab);
}

void	make_forks(t_table	*tab)
{
	int	i;

	i = 0;
	while (i <= tab->philos_num)
	{
		pthread_mutex_init(&(tab->forks[i]), NULL);
		++i;
	}
}

t_philo	*create_chain(t_table *tab)
{
	int		i;
	t_philo	*head;
	t_philo	*prev;

	i = 1;
	head = add_philosopher(1);
	prev = head;
	while (i++ < tab->philos_num)
	{
		prev->next = add_philosopher(i);
		prev->next->prev = prev;
		prev->table = tab;
		pthread_create(&(prev->philosopher), NULL, &routine, (void *)prev);
		prev = prev->next;
	}
	prev->next = head;
	prev->table = tab;
	pthread_create(&(prev->philosopher), NULL, &routine, (void *)prev);
	head->prev = prev;
	tab->head = head;
	return (head);
}
