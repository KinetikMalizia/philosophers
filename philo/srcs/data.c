/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:07:27 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/28 15:59:05 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_phi(t_philo *head)
{
	t_philo	*current;

	current = head;
	while (current->philo_id != current->table->philos_num)
	{
		printf("id:%d\n", current->philo_id);
		if (current->next)
			printf("next is: %d\n", current->next->philo_id);
		if (current->prev)
			printf("prev is: %d\n", current->prev->philo_id);
		printf("last meal: %ld\n", current->last_meal);
		printf("num meal: %d\n", current->num_meals);
		printf("-----------------------------\n");
		current = current->next;
	}
	printf("id:%d\n", current->philo_id);
	if (current->next)
		printf("next is: %d\n", current->next->philo_id);
	if (current->prev)
		printf("prev is: %d\n", current->prev->philo_id);
	printf("last meal: %ld\n", current->last_meal);
	printf("num meal: %d\n", current->num_meals);
	printf("-----------------------------\n");
}

int	smart_sleep(long ms, t_table *tab)
{
	long	start;
	long	time;

	start = current_time();
	time = current_time();
	while ((time - start) <= ms - 1 || tab->someonedied)
	{
		usleep(10);
		time = current_time();
	}
	return (tab->someonedied);
}

long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_action(char *status, t_philo *philo)
{
	pthread_mutex_lock(&(philo->table->print_locker));
	if (!(philo->table->someonedied))
		printf("%ld\tphilo %d\t%s\n",
			current_time() - philo->table->start_time, philo->philo_id, status);
	pthread_mutex_unlock(&(philo->table->print_locker));
}

void	print_fork(char *status, t_philo *philo, int f)
{
	pthread_mutex_lock(&(philo->table->print_locker));
	if (!(philo->table->someonedied))
		printf("%ld\tphilo %d\t%s %d\n",
			current_time() - philo->table->start_time, philo->philo_id, status, f);
	pthread_mutex_unlock(&(philo->table->print_locker));
}

/*
void	print_action(int num, char *status, t_data *data)
{
	static int	shutdown = 0;

	pthread_mutex_lock(&data->print);
	if (shutdown == 1)
		return ;
	if (!ft_strncmp(status, DIED, ft_strlen(status)))
		shutdown = 1;
	printf("%ld\t %d %s\n", current_time() - data->start, num, status);
	pthread_mutex_unlock(&data->print);
}
*/