/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:50:57 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/21 15:48:59 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_philo	*add_philosopher(int id)
{
	t_philo	*new;

	printf("creating philo: %d", id);
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
	tab->forks = malloc(sizeof(pthread_mutex_t) * tab->philos_num);
	pthread_mutex_init(&(tab->print_locker), NULL);
	tab->head = NULL;
	return (tab);
}

t_philo	*create_chain(t_table tab)
{
	int		i;
	t_philo	*head;
	t_philo	*prev;
	t_philo	*next;

	i = 1;
	printf("dead");
	head = add_philosopher(1);
	prev = head;
	while (i++ < tab.philos_num)
	{
		prev->next = add_philosopher(i);
		prev->next->prev = prev;
	}
	return (head);
}
