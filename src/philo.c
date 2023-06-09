/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:58:26 by vcodrean          #+#    #+#             */
/*   Updated: 2023/06/01 13:18:53 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation(t_data *pdata)
{
	pthread_mutex_init(&pdata->mtx_last_eat, NULL);
	pthread_mutex_init(&pdata->mtx_status, NULL);
	pdata->status = 0;
	pdata->idphilo = 1;
	if (philo_init(pdata) == 1)
		return (1);
	if (mutex_init(pdata) == 1)
		return (1);
	pdata->time_s = get_time();
	if (thread_init(pdata) == 1)
		return (1);
	pdata->set_philo = 1;
	ckeck_philo(pdata);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*pdata;

	if (ac < 5 || ac > 6)
	{
		printf("Error\nBad number of argument\n");
		return (1);
	}
	pdata = malloc(sizeof(t_data));
	if (!pdata)
		return (0);
	if (parse_params(ac, av, pdata) == 1)
	{
		printf("Error\nNon valid arguments\n");
		return (1);
	}
	if (simulation(pdata) != 0)
	{
		printf("Error\nSimulation failed\n");
		return (1);
	}
	return (0);
}
