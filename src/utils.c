/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:04:08 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/22 14:57:00 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int ph_atoi(const char *str)
{
    int i;
    int sign;
    long int nbr;

    i = 0;
    sign = 1;
    nbr = 0;
    while((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
        i++;
    if((str[i] == '-') || (str[i] == '+'))
    {
        if(str[i]== '-')
            sign = -1;
        i++;      
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        nbr = nbr * 10 + (str[i] - '0');
        i++;        
    }
    nbr = nbr * sign;
    if (nbr > 2147483647)
        return(-1);
    return(nbr);    
}
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return(i);
}