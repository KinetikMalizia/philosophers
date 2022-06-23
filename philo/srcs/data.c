/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:07:27 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/23 16:32:54 by fmalizia         ###   ########.ch       */
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
