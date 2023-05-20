/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:05:15 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/20 17:42:25 by vcodrean         ###   ########.fr       */
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
int start_sim(t_data *pdata);
void init_philo(t_data *data);

#endif
