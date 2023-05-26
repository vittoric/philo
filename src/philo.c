/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:58:26 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/26 14:29:44 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*used to check whether the arguments entered on the command 
line are valid before assigning them to the corresponding 
variables in the t_data structure. Its main purpose is to check 
that the arguments are positive integers.*/

int    check_arg(int ac, char **av)
{
    int num;
    int i;

    num = 1;
    while(num < ac)
    {
        i = 0;
        if(av[num][i] == '+' && (ft_strlen(av[num]) > 1))
            i++;
        while(av[num][i])
        {
            if(av[num][i] < '0' || av[num][i] > '9')
                return(0);
            i++;
        }
        num++;
    }
    return(1);
    
}

int parse_params(int ac, char **av, t_data *pdata)
{
    if(check_arg(ac, av) == 1)
    {
        pdata->num_of_philo = ph_atoi(av[1]);
        pdata->forks = pdata->num_of_philo;
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
        pdata->philo_meals = -1;
    return(0);
}



int philo_init(t_data *pdata)
{
    int idx;

    idx = 0;
    pdata->set_philo = 0;
    pdata->thread = malloc(sizeof(pthread_t *) * (pdata->num_of_philo));
    if(!pdata->thread)
        return(1);
    pdata->philo = malloc(sizeof(t_philosopher) * pdata->num_of_philo);
    if (!pdata->philo)
        return(1);
    pthread_mutex_init(&pdata->mutex_idx, NULL);
    pthread_mutex_init(&pdata->mutex_print, NULL);
    pthread_mutex_init(&pdata->mutex_fork, NULL);
    while(idx < pdata->num_of_philo)
    {
        pdata->philo[idx].meals = 0;
        pdata->philo[idx].left_fork = idx - 1;
        pdata->philo[idx].right_fork = idx;
        idx++;
    }
    pdata->philo[0].left_fork = pdata->num_of_philo - 1;

    printf("fork %d\n", pdata->philo->left_fork);
    
    return(0);
}

int mutex_init(t_data *pdata)
{
    int idx;

    idx = 0;
    while (idx < pdata->num_of_philo)
    {
        if(pthread_mutex_init(&pdata->mutex[idx], NULL) != 0)
            return(1);
        idx++;
    }
    return(0);
}
/*
int init_routine(t_data *pdata)
{
    
}*/

int check_death(t_data *pdata)
{
    long time;
    int idx;
    
    idx = 0;
    while (idx < pdata->num_of_philo)
    {
        time = get_time() - pdata->time_s;
        if( (time - pdata->philo[idx].last_meal > pdata->time_to_die))
        {
            if (pdata->begin == 0)
            {
                pdata->begin = 1;
                printf("[%zu] 🅓🅘🅔🅓    [%d]  philo died ⒹⒾⒺⒹ 💀", time, idx + 1);
            }
        }
        idx++;
    }
    return (0);
}

int meal_ckeack(t_data *pdata)
{
    int idx;
    int num;

    idx = 0;
    num = 0;
    if (!pdata->philo_meals)
        return(0);
    while (idx < pdata->num_of_philo)
    {
        if (pdata->philo[idx].meals >= pdata->philo_meals)
            num++;
        else
            break;
        idx++;
    }
    if (num >= pdata->num_of_philo)
    {
        pdata->begin = 2;
        return(1);
    }
    return(0);
}


void    st_print(char *str, t_data *pdata, int n)
{
    long    time;

    time = get_time() - pdata->time_s;
    pthread_mutex_lock(&pdata->mutex_print);
    if (n <= pdata->num_of_philo && meal_ckeack(pdata) == 0 && pdata->begin == 0)
    {
        printf("%ld   %d     %s", time, n, str);
    }
    pthread_mutex_unlock(&pdata->mutex_print);
}

void    take_fork(t_data *pdata, int n)
{
    pthread_mutex_lock(&pdata->mutex[pdata->philo[n].right_fork]);
    st_print("Take a fork", pdata, n + 1);
    if(pdata->num_of_philo == 1)
        to_usleep(pdata->time_to_die + 1);
    pthread_mutex_lock(&pdata->mutex[pdata->philo[n].left_fork]);
    st_print("Take a fork", pdata, n + 1);
    
}

void *routine(void *d)
{
    t_data *data;
    int idx;
    
    data = (t_data *)d;
    idx = data->idphilo - 1;    
    pthread_mutex_lock(&data->mutex_idx);
    data->idphilo++;
    pthread_mutex_unlock(&data->mutex_idx);
    
    if(idx % 2 == 0)
        to_usleep(data->time_to_eat / 2);
    while(data->set_philo == 0)
    {
        usleep(10);
    }
    while(data->begin == 0 || check_death(data) == 0)
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

int thread_init(t_data *pdata)
{
    int idx;

    idx = 0;
    while(idx < pdata->num_of_philo)
    {
        pthread_mutex_lock(&pdata->mtx_last_eat);
        pdata->philo[idx].last_meal = 0;
        pthread_mutex_unlock(&pdata->mtx_last_eat);
        if(pthread_create(&pdata->thread[idx], NULL, &routine, (void*)pdata) != 0)
            return(1);
        idx++;
    }
    return(0);
}

int simulation(t_data *pdata)
{
    pthread_mutex_init(&pdata->mtx_last_eat, NULL);
    pthread_mutex_init(&pdata->mtx_status, NULL);
    pdata->status = 0,
    pdata->idphilo = 1;
    if (philo_init(pdata) == 1)
        return(1);
    if(mutex_init(pdata) == 1)
        return(1);
    pdata->time_s = get_time();
    if (thread_init(pdata) == 1)
        return(1);
    return(0);
}


int main(int ac, char **av)
{
    t_data *pdata;

    pdata = malloc(sizeof(t_data));
    if(!pdata)
        return(0);    
    if(ac < 5 || ac > 6)
    {
        printf("Error\nBad number of argument\n");
        return(1);
    }    
    if(parse_params(ac, av, pdata) == 1)
    {
        printf ("Error\nNon valid arguments\n");
        return(1);
    }
    if (simulation(pdata) != 0)
    {
        printf ("Error\nSimulation failed\n");
        return (1);
    }    
    return(0);
}
