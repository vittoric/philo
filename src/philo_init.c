/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:36:54 by vcodrean          #+#    #+#             */
/*   Updated: 2023/06/01 13:18:47 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_init(t_data *pdata)
{
	int	idx;

	idx = 0;
	pdata->set_philo = 0;
	pdata->thread = malloc(sizeof(pthread_t *) * (pdata->num_of_philo));
	if (!pdata->thread)
		return (1);
	pdata->philo = malloc(sizeof(t_philosopher) * pdata->num_of_philo);
	if (!pdata->philo)
		return (1);
	pdata->mutex = malloc(sizeof(pthread_mutex_t) * pdata->num_of_philo);
	if (!pdata->mutex)
		return (1);
	pthread_mutex_init(&pdata->mutex_idx, NULL);
	pthread_mutex_init(&pdata->mutex_print, NULL);
	pthread_mutex_init(&pdata->mutex_fork, NULL);
	while (idx < pdata->num_of_philo)
	{
		pdata->philo[idx].meals = 0;
		pdata->philo[idx].right_fork = idx - 1;
		pdata->philo[idx].left_fork = idx;
		idx++;
	}
	pdata->philo[0].right_fork = pdata->num_of_philo - 1;
	return (0);
}
/*used to check whether the arguments entered on the command 
line are valid before assigning them to the corresponding 
variables in the t_data structure. Its main purpose is to check 
that the arguments are positive integers.*/

int	parse_params(int ac, char **av, t_data *pdata)
{
	if (check_arg(ac, av) == 1)
	{
		pdata->num_of_philo = ph_atoi(av[1]);
		pdata->time_to_die = ph_atoi(av[2]);
		pdata->time_to_eat = ph_atoi(av[3]);
		pdata->time_to_sleep = ph_atoi(av[4]);
		if (av[5])
			pdata->philo_meals = ph_atoi((av[5]));
	}
	else
		return (1);
	if ((pdata->num_of_philo <= 0 || pdata->num_of_philo > 200) || \
pdata->time_to_die < 60 || pdata->time_to_eat <= 60 || \
pdata->time_to_sleep < 60)
		return (1);
	if (!av[5])
		pdata->philo_meals = 0;
	return (0);
}
