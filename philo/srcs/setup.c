/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:50:57 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/20 16:43:50 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "types.h"

*t_philo	add_philosopher(t_philo	*head, int id)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	new->philo_id = id;
	new->last_meal = 0;
	new->num_meals = 0;

}

*t_table	set_table(int ac, char **av)
{
	t_table	*tab;

	tab = malloc(sizeof(t_table));
	tab->philos_num = ft_atoi(av[1]);
	tab->time_to_die = ft_atoi(av[2]);
	tab->time_to_eat = ft_atoi(av[3]);
	tab->time_to_sleep = ft_atoi(av[4]);
	if(ac == 6)
		tab->eat_num = ft_atoi(av[5]);
	else
		tab->eat_num == -1;
	tab->someonedied = FALSE;
	tab->head == NULL;

	return (tab);
}