/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:52:46 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/23 13:00:40 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t get_time(void)
{
    struct timeval  time;
    size_t          actual_time;

    gettimeofday(&time, NULL);
    actual_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return(actual_time);
}