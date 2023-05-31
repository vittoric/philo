/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:40:11 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/31 16:02:08 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int meal_ckeack(t_data *pdata)
{
    int idx;
    int num;

    idx = -1;
    num = 0;
   
    if (!pdata->philo_meals)
        return(0);
   
    while (++idx < pdata->num_of_philo)
    {
        if (pdata->philo[idx].meals >= pdata->philo_meals)
            num++;
        else
            break;
        //idx++;
    } 
    if (num >= pdata->num_of_philo)
    {
        pdata->status = 2;
        return(1);
    }
    return(0);
}

void ckeck_philo(t_data *pdata)
{
    int idx;
    long time;

    idx = -1;
    while(pdata->status == 0)
    {
        while(++idx < pdata->num_of_philo)
        {
            time = get_time() - pdata->time_s;
            
            if ( time - pdata->philo[idx].last_meal > pdata->time_to_die || meal_ckeack(pdata) == 1)
            {
               
                if ( pdata->status == 2)
                {
                    break;
                }
                pdata->status = 1;
                pr_philo_death(time, idx + 1);
                break;
            }
            //idx++;
        }
        idx = -1;
    }
    free_philo(pdata);
}

