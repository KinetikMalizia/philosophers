/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:02:16 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/28 15:59:00 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine(void *data)
{
	t_philo	*phil;

	phil = (t_philo *)data;
	if (phil->philo_id % 2)
	{
		print_action("is\tthinking 💭", phil);
		smart_sleep(phil->table->time_to_eat / 2, phil->table);
	}
	while (!(phil->table->someonedied))
	{
		eat_action(phil);
		sleep_action(phil);
		print_action("is\tthinking 💭", phil);
	}
	return (NULL);
}

void	sleep_action(t_philo *phil)
{
	print_action("is\tsleeping 💤", phil);
	smart_sleep(phil->table->time_to_sleep, phil->table);
}

void	eat_action(t_philo	*phil)
{
	if (phil->table->someonedied)
		return ;
	pthread_mutex_lock(&(phil->table->forks[phil->philo_id]));
	print_fork("took fork", phil, phil->philo_id);
	pthread_mutex_lock(&(phil->table->forks[phil->prev->philo_id]));
	print_fork("took fork", phil, phil->prev->philo_id);
	print_action("is\teating   🍝", phil);
	phil->last_meal = current_time();
	phil->num_meals += 1;
	smart_sleep(phil->table->time_to_eat, phil->table);
	pthread_mutex_unlock(&(phil->table->forks[phil->prev->philo_id]));
	print_fork("put down fork", phil, phil->prev->philo_id);
	pthread_mutex_unlock(&(phil->table->forks[phil->philo_id]));
	print_fork("put down fork", phil, phil->philo_id);
}

void	*death_monitor(void	*data)
{
	t_table	*tab;
	t_philo	*phil;

	tab = (t_table *)data;
	phil = tab->head;
	while (!(tab->someonedied))
	{
		if (current_time() - tab->start_time
			> phil->last_meal + tab->time_to_die)
		{
			tab->someonedied = 1;
			pthread_mutex_lock(&tab->print_locker);
			printf("%ld\tphilo %d is %s\n", current_time()
				- phil->table->start_time, phil->philo_id, "DEAD 💀");
			pthread_mutex_unlock(&tab->print_locker);
		}
		phil = phil->next;
	}
	return (NULL);
}
