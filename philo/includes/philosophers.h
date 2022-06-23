/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:14:57 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/23 15:35:34 by fmalizia         ###   ########.ch       */
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
int		ft_isdigit(int a);
t_table	*set_table(int ac, char **av);
t_philo	*add_philosopher(int id);
t_philo	*create_chain(t_table *tab);
int		input_check(int ac, char **av);
void	join(t_philo *phil);
/*--------------------------------------------------*/
void	print_phi(t_philo *head);
void	*routine(void *data);

#endif