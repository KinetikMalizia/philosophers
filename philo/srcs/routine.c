/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:02:16 by fmalizia          #+#    #+#             */
/*   Updated: 2022/07/01 16:52:14 by fmalizia         ###   ########.ch       */
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
	phil->last_meal = current_time() - phil->table->start_time;
	phil->num_meals += 1;
	smart_sleep(phil->table->time_to_eat, phil->table);
	if (phil->num_meals == phil->table->eat_num)
		print_action("has eaten enough", phil);
	pthread_mutex_unlock(&(phil->table->forks[phil->prev->philo_id]));
	pthread_mutex_unlock(&(phil->table->forks[phil->philo_id]));
}

void	*death_monitor(void	*data)
{
	t_table	*tab;
	t_philo	*phil;
	int		done;

	done = 0;
	tab = (t_table *)data;
	phil = tab->head;
	while (!(tab->someonedied))
	{
		if (phil->num_meals >= tab->eat_num && tab->eat_num > 0)
			++done;
		else
			done = 0;
		if (done >= tab->philos_num)
			break ;
		if (current_time() - tab->start_time
			> phil->last_meal + tab->time_to_die + 1)
		{
			tab->someonedied = 1;
			print_death(phil);
		}
		phil = phil->next;
		usleep(5);
	}
	return (NULL);
}
