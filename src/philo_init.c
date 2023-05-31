/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:36:54 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/30 18:00:18 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_init(t_data *pdata)
{
    int idx;

    idx = 0;
    pdata->set_philo = 0;
    pdata->thread = malloc(sizeof(pthread_t *) * (pdata->num_of_philo));
    if(!pdata->thread)
        return(-1);
    pdata->philo = malloc(sizeof(t_philosopher) * pdata->num_of_philo);
    if (!pdata->philo)
        return(-1);
    pdata->mutex = malloc(sizeof(pthread_mutex_t) * pdata->num_of_philo);
    if (!pdata->mutex)
        return(-1);
    pthread_mutex_init(&pdata->mutex_idx, NULL);
    pthread_mutex_init(&pdata->mutex_print, NULL);
    pthread_mutex_init(&pdata->mutex_fork, NULL);
    while(idx < pdata->num_of_philo)
    {
        pdata->philo[idx].meals = 0;
        pdata->philo[idx].right_fork = idx - 1;
        pdata->philo[idx].left_fork= idx;
        idx++;
    }
    pdata->philo[0].right_fork = pdata->num_of_philo - 1;    
    return(0);
}