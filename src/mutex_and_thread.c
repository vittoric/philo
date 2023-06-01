/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_and_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:38:30 by vcodrean          #+#    #+#             */
/*   Updated: 2023/06/01 13:05:01 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_data *pdata)
{
	int	idx;

	idx = 0;
	while (idx < pdata->num_of_philo)
	{
		if (pthread_mutex_init(&pdata->mutex[idx], NULL) != 0)
			return (1);
		idx++;
	}
	return (0);
}

int	thread_init(t_data *pdata)
{
	int	idx;

	idx = 0;
	while (idx < pdata->num_of_philo)
	{
		pthread_mutex_lock(&pdata->mtx_last_eat);
		pdata->philo[idx].last_meal = 0;
		pthread_mutex_unlock(&pdata->mtx_last_eat);
		if (pthread_create(&pdata->thread[idx], NULL, &routine, \
		(void *)pdata) != 0)
			return (1);
		idx++;
	}
	return (0);
}
