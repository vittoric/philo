/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:41:08 by vcodrean          #+#    #+#             */
/*   Updated: 2023/06/05 16:56:46 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *pdata)
{
	t_data	*data;
	int		idx;

	data = (t_data *)pdata;
	while (data->set_philo == 0)
		usleep(50);
	pthread_mutex_lock(&data->mutex_idx);
	idx = data->idphilo - 1;
	data->idphilo++;
	pthread_mutex_unlock(&data->mutex_idx);
	if (idx % 2 == 0)
		to_usleep(data->time_to_eat / 2);
	while (data->status == 0 || check_death(data) == 0)
	{
		pthread_mutex_lock(&data->mutex_fork);
		take_fork(data, idx);
		pthread_mutex_unlock(&data->mutex_fork);
		philo_eat(data, idx);
		philo_sleep(data, idx);
		if (data->num_of_philo % 2 != 0)
			to_usleep(data->time_to_sleep / 3);
	}
	return (NULL);
}

void	free_philo(t_data *pdata)
{
	int	idx;

	idx = 0;
	while (idx < pdata->num_of_philo)
	{
		pthread_mutex_destroy(&pdata->mutex[idx]);
		idx++;
	}
	idx = 0;
	while (idx < pdata->num_of_philo)
	{
		pthread_detach(pdata->thread[idx]);
		idx++;
	}
}
