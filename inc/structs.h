/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:05:41 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/18 16:37:57 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "philo.h"

typedef struct s_data
{
       int  num_of_philo;
       int  forks;
       int  time_to_die;
       int  time_to_eat;
       int  time_to_sleep;
       int  meals;
       
}   t_data;

/*
typedef struct s_philo
{
        
}   t_philo;
*/
#endif
