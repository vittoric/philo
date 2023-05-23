/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:05:15 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/23 13:12:06 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include "structs.h"

int         main(int ac, char **av);
int         parse_params(int ac, char **av, t_data *data);

//utils
long int    ph_atoi(const char *str);
int         ft_strlen(char *str);

//core functions
int simulation(t_data *pdata);
int philo_init(t_data *pdata);
void routine(void *d);

//mutex
int mutex_init(t_data *pdata);

//time func's 
size_t get_time(void);

#endif
