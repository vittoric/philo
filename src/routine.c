/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:41:08 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/31 17:50:16 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_death(t_data *pdata)
{
    long time;
    int idx;
    
    idx = -1;
    while (++idx < pdata->num_of_philo)
    {
        time = get_time() - pdata->time_s;
        if (time - pdata->philo[idx].last_meal > pdata->time_to_die)
        {
            if (pdata->status == 0)
            {
                pdata->status = 1;
                printf("\033[1;4;33m[ %ld ]\033[0m \033[1;4;33m[ %d ]\033[0m \
    \033[1m\033[31mIs dead\033[0m💀", time, idx);
            }
            return(1);
        }
        //idx++;
    }
    return (0);
}


void *routine(void *d)
{
    t_data *data;
    int idx;
    
    data = (t_data *)d;
    idx = data->idphilo - 1;   
    while(data->set_philo == 0)
    {
        usleep(10); 
    }  
    pthread_mutex_lock(&data->mutex_idx);
    data->idphilo++; 
    pthread_mutex_unlock(&data->mutex_idx);  
    if(idx % 2 == 0)
        to_usleep(data->time_to_eat / 2);
    while(data->status == 0 || check_death(data) == 0)
    {
        pthread_mutex_lock(&data->mutex_fork);
        take_fork(data, idx);
        pthread_mutex_unlock(&data->mutex_fork);
        philo_eat(data, idx);
        philo_sleep(data, idx);
        if(data->num_of_philo % 2 != 0)
            to_usleep(data->time_to_sleep / 3);
    }
    return(NULL);
}
