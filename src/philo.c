/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:58:26 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/20 18:07:52 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return(i);
}

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
            pdata->meals = ph_atoi((av[5]));
        /*else
            pdata->meals = -1;*/
    }
    else
        return(1);
    if(pdata->num_of_philo <= 1 || pdata->time_to_die <= 0 || pdata->meals <= 0 \
        || pdata->time_to_eat <= 0 || pdata->time_to_sleep <= 0)
            return(1);
    if(!av[5])
        pdata->meals = -1;
    return(0);
}

void init_philo(t_data *data)
{
    int idx;

    idx = 0;
    while(idx < data->num_of_philo)
    {
        data->philo[idx].pid = idx + 1;
        data->philo[idx].status = 1;
        data->philo[idx].action = 0;
        data->philo[idx].meals_res = 0;
        data->philo[idx].info = data;
        //data->philo[idx].time = calc_time();
        //data->philo[idx].last_meal = data->philo[idx].time;
        data->fork[idx].fid = idx + 1;
        data->fork[idx].vacant = 1;
        idx++;
    }
}
int start_sim(t_data *pdata)
{
    init_philo(pdata);
    return(0);
}
int main(int ac, char **av)
{
    t_data pdata;

   // pdata = malloc(sizeof(t_data));
    if(ac < 5 || ac > 6)
    {
        printf("Error\nBad number of argument\n");
        return(1);
    }    
    if(parse_params(ac, av, &pdata) == 1)
    {
        printf("Error\nNon valid arguments\n");
        return(1);
    }
    if(start_sim(&pdata) != 0)
    {
        printf("Error\nSimulation failed\n");
        return(1);
    }
    





    
    printf("Num of philo 🙇‍: %d\n", pdata.num_of_philo);
    printf("Forks 🍴: %d\n", pdata.forks);
    printf("Time to die 💀: %d\n", pdata.time_to_die);
    printf("Time to eat 😋: %d\n", pdata.time_to_eat);
    printf("Time to sleep 😴: %d\n", pdata.time_to_sleep);
    printf("Meals 🍝: %d\n", pdata.meals);
    
    return(0);
}