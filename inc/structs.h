/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:05:41 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/20 18:00:40 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "philo.h"

typedef struct s_fork
{
       int fid;
       int vacant;
}      t_fork;

typedef struct s_philosopher
{
       int pid;
       int status;
       int action;
       int meals_res;
       size_t last_meal;
       size_t time;
       struct s_data *info;
}   t_philosopher;

typedef struct s_data
{
       int  num_of_philo;
       int  forks;
       int  time_to_die;
       int  time_to_eat;
       int  time_to_sleep;
       int  meals;
       struct s_philosopher *philo;
       struct s_fork *fork;
       
}   t_data;

#endif
