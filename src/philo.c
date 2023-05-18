/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:58:26 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/18 17:25:45 by vcodrean         ###   ########.fr       */
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

int get_argc(int ac, char **av, t_data *data)
{
    if(check_arg(ac, av) == 1)
    {
        data->num_of_philo = ph_atoi(av[1]);
        data->forks = data->num_of_philo;
        data->time_to_die = ph_atoi(av[2]);
        data->time_to_eat = ph_atoi(av[3]);
        data->time_to_sleep = ph_atoi(av[4]);
        if(av[5])
            data->meals = ph_atoi((av[5]));
    }
    else
        return(1);
    if(data->num_of_philo < 0 || data->time_to_die < 0 || data->meals < 0 \
        || data->time_to_eat < 0 || data->time_to_sleep < 0)
        return(1);
    if(!av[5])
        data->meals = -1;
    return(0);
}
int main(int ac, char **av)
{
    t_data data;
    if(ac < 5 || ac > 6)
    {
        printf("Error\nBad number of argument\n");
        return(1);
    }    
    if(get_argc(ac, av, &data) == 1)
    {
        printf("Error\nBad argument\n");
        return(1);
    }
    
    printf("Num of philo 🙇‍♀️: %d\n", data.num_of_philo);
    printf("Forks 🍴: %d\n", data.forks);
    printf("Time to die 💀: %d\n", data.time_to_die);
    printf("Time to eat 😋: %d\n", data.time_to_eat);
    printf("Time to sleep 😴: %d\n", data.time_to_sleep);
    printf("Meals 🍝: %d\n", data.meals);
    
    return(0);
}