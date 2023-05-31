/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:58:26 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/31 17:30:12 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*used to check whether the arguments entered on the command 
line are valid before assigning them to the corresponding 
variables in the t_data structure. Its main purpose is to check 
that the arguments are positive integers.*/

int parse_params(int ac, char **av, t_data *pdata)
{
    if(check_arg(ac, av) == 1)
    {
        pdata->num_of_philo = ph_atoi(av[1]);
        pdata->time_to_die = ph_atoi(av[2]);
        pdata->time_to_eat = ph_atoi(av[3]);
        pdata->time_to_sleep = ph_atoi(av[4]);
        if(av[5])
            pdata->philo_meals= ph_atoi((av[5]));
    }
    else
        return(1);
    if((pdata->num_of_philo <= 0 || pdata->num_of_philo > 200) || \
        pdata->time_to_die < 60 ||  pdata->time_to_eat <= 60 || \
        pdata->time_to_sleep < 60)
            return(1);
    if(!av[5])
        pdata->philo_meals = 0;
    return(0);
}








void free_philo(t_data *pdata)
{
    int idx;

    idx = -1;
    while (++idx < pdata->num_of_philo)
    {
        pthread_mutex_destroy(&pdata->mutex[idx]);
        //idx++;
    }

    idx = 0;
    while (idx < pdata->num_of_philo)
    {
        pthread_detach(pdata->thread[idx]);
        idx++;
    }
}



static int simulation(t_data *pdata)
{
     
    pthread_mutex_init(&pdata->mtx_last_eat, NULL);
    pthread_mutex_init(&pdata->mtx_status, NULL);
    pdata->status = 0;   
    pdata->idphilo = 1;
    if (philo_init(pdata) == 1)
        return(-1);
    if(mutex_init(pdata) == 1)
        return(-1);
    pdata->time_s = get_time();
    if (thread_init(pdata) == 1)
        return(-1);
    
    pdata->set_philo = 1;
    ckeck_philo(pdata);   
    return(0);
}


int main(int ac, char **av)
{
    t_data *pdata;

    if(ac < 5 || ac > 6)
    {
        printf("Error\nBad number of argument\n");
        return(1);
    }   
    pdata = malloc(sizeof(t_data));
    if(!pdata)
        return(0);  
    if(parse_params(ac, av, pdata) == 1)
    {
        printf ("Error\nNon valid arguments\n");
        return(1);
    }
    if (simulation(pdata) != 0)
    {
        printf ("Error\nSimulation failed\n");
        return (-1);
    }  
    return(0);
}
