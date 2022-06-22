/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:14:55 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/22 17:03:51 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_philo
{
	int				philo_id;
	pthread_t		philosopher;
	struct s_philo	*next;
	struct s_philo	*prev;
	long			last_meal;
	int				num_meals;
	struct s_table	*table;
}				t_philo;

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
	struct s_philo	*head;
}				t_table;

#endif