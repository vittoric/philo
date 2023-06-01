/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:44:45 by vcodrean          #+#    #+#             */
/*   Updated: 2023/06/01 13:03:29 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	st_print(char *str, t_data *pdata, int n)
{
	long	time;

	time = get_time() - pdata->time_s;
	pthread_mutex_lock(&pdata->mutex_print);
	if (n <= pdata->num_of_philo && meal_ckeack(pdata) == 0 \
	&& pdata->status == 0)
	{
		printf("\033[1;4;33m[ %ld ]\033[0m \033[1;4;33m[ %d ]\033[0m   %s\n", \
		time, n, str);
	}
	pthread_mutex_unlock(&pdata->mutex_print);
}

void	take_fork(t_data *pdata, int n)
{
	pthread_mutex_lock(&pdata->mutex[pdata->philo[n].right_fork]);
	st_print("\033[1m\033[34mTook a right fork\033[0m 🍴", pdata, n + 1);
	if (pdata->num_of_philo == 1)
		to_usleep(pdata->time_to_die + 1);
	pthread_mutex_lock(&pdata->mutex[pdata->philo[n].left_fork]);
	st_print("\033[1m\033[36mTook a left fork 🍴\033[0m", pdata, n + 1);
}

void	philo_eat(t_data *pdata, int num)
{
	st_print("\033[1m\033[32mIs eating\033[0m😋", pdata, num + 1);
	pdata->philo[num].meals++;
	to_usleep(pdata->time_to_eat);
	pthread_mutex_unlock(&pdata->mutex[pdata->philo[num].left_fork]);
	pthread_mutex_unlock(&pdata->mutex[pdata->philo[num].right_fork]);
	pthread_mutex_lock(&pdata->mtx_last_eat);
	pdata->philo[num].last_meal = get_time() - pdata->time_s;
	pthread_mutex_unlock(&pdata->mtx_last_eat);
}

void	philo_sleep(t_data *pdata, int num)
{
	st_print("\033[1m\033[33mIs sleeping\033[0m😴", pdata, num +1);
	to_usleep(pdata->time_to_sleep);
	st_print("\033[1m\033[35mIs thinking\033[0m🙇", pdata, num + 1);
}

void	pr_philo_death(long time, int idx)
{
	printf("\033[1;4;33m[ %ld ]\033[0m \033[1;4;33m[ %d ]\033[0m \
	\033[1m\033[31mIs dead\033[0m💀", time, idx);
}
