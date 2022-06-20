/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:14:57 by fmalizia          #+#    #+#             */
/*   Updated: 2022/06/20 16:43:36 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "types.h"
# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
# include<pthread.h>
# include<unistd.h>
# include<sys/time.h>

# define FALSE 0
# define TRUE 1

int			ft_atoi(const char *str);
*t_table	set_table(int ac, char **av);

#endif