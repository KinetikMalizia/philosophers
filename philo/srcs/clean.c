/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:04:58 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/30 12:58:55 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	kill_philos(t_philo	*head)
{
	t_philo	*current;
	t_philo	*next;
	int		i;

	current = head;
	i = 1;
	while (i <= head->table->philos_num)
	{
		next = current->next;
		free(current);
		current = next;
		++i;
	}
}

void	clean_table(t_table *tab)
{
	int	i;

	i = 0;
	pthread_mutex_unlock(&tab->print_locker);
	pthread_mutex_destroy(&tab->print_locker);
	while (i <= tab->philos_num)
	{
		pthread_mutex_unlock(&tab->forks[i]);
		pthread_mutex_destroy(&tab->forks[i]);
		i++;
	}
	free(tab->forks);
}
