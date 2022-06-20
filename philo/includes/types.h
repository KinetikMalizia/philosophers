/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:14:55 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/20 16:43:29 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "philosophers.h"

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				philo_id;
	pthread_t		philosopher;
	struct s_philo *next;
	struct s_philo *prev;
	long			last_meal;
	int				num_meals;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_num;
	int				someonedied;
	pthread_mutex_t	print_locker;
	pthread_mutex_t	*forks;
	t_philo			*head;
}	t_table;

#endif