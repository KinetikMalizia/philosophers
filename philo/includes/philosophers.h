/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:14:57 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/29 15:38:04 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
# include<pthread.h>
# include<unistd.h>
# include<sys/time.h>
# include "./types.h"

# define FALSE 0
# define TRUE 1
# define INT_MAX 2147483647
# define INT_MIN -2147483648

int		ft_atoi(const char *str);
t_table	*set_table(int ac, char **av);
t_philo	*add_philosopher(int id);
t_philo	*create_chain(t_table *tab);
int		input_check(int ac, char **av);
void	join(t_philo *phil);
/*--------------------------------------------------*/
void	print_phi(t_philo *head);
void	*routine(void *data);
int		smart_sleep(long ms, t_table *tab);
long	current_time(void);
void	print_action(char *status, t_philo *philo);
void	eat_action(t_philo	*phil);
void	sleep_action(t_philo *phil);
void	make_forks(t_table	*tab);
void	*death_monitor(void	*data);
void	print_fork(char *status, t_philo *philo, int f);
void	print_death(t_philo	*phil);
int		check_if_digit(int ac, char **av);
void	print_meals(t_philo *phil);

#endif