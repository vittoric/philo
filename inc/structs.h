/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:05:41 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/22 19:11:41 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "philo.h"


typedef struct s_philosopher
{
       int    meals;
       size_t last_meal;
       int    left_fork;
       int    right_fork;
       struct s_data *data;
}   t_philosopher;

typedef struct s_data
{
       int                  idphilo;
       int                  num_of_philo;
       int                  forks;
       int                  time_to_die;
       int                  time_to_eat;
       int                  time_to_sleep;
       int                  time_to_think;
       int                  philo_meals;
       int                  status;
       int                  set_ph;
       pthread_t            *thread;
       t_philosopher        *philo;
       pthread_mutex_t      *mutex;
       pthread_mutex_t      mutex_fork;
       pthread_mutex_t      mutex_idx;
       pthread_mutex_t      mutex_print;    
       pthread_mutex_t      mtx_last_eat;
       pthread_mutex_t      mtx_status;
       size_t              time_s;       
}   t_data;

#endif
