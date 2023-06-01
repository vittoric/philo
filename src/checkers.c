/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:40:11 by vcodrean          #+#    #+#             */
/*   Updated: 2023/06/01 13:19:20 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	meal_ckeack(t_data *pdata)
{
	int	idx;
	int	num;

	idx = 0;
	num = 0;
	if (!pdata->philo_meals)
		return (0);
	while (idx < pdata->num_of_philo)
	{
		if (pdata->philo[idx].meals >= pdata->philo_meals)
			num++;
		else
			break ;
		idx++;
	}
	if (num >= pdata->num_of_philo)
	{
		pdata->status = 2;
		return (1);
	}
	return (0);
}

void	ckeck_philo(t_data *pdata)
{
	int		idx;
	long	time;

	idx = 0;
	while (pdata->status == 0)
	{
		while (idx < pdata->num_of_philo)
		{
			time = get_time() - pdata->time_s;
			if (time - pdata->philo[idx].last_meal > pdata->time_to_die || \
			meal_ckeack(pdata) == 1)
			{
				if (pdata->status == 2)
				{
					break ;
				}
				pdata->status = 1;
				pr_philo_death(time, idx + 1);
				break ;
			}
			idx++;
		}
		idx = 0;
	}
	free_philo(pdata);
}

int	check_death(t_data *pdata)
{
	long	time;
	int		idx;

	idx = 0;
	while (idx < pdata->num_of_philo)
	{
		time = get_time() - pdata->time_s;
		if (time - pdata->philo[idx].last_meal > pdata->time_to_die)
		{
			if (pdata->status == 0)
			{
				pdata->status = 1;
				printf("\033[1;4;33m[ %ld ]\033[0m \033[1;4;33m[ %d ]\033[0m \
	\033[1m\033[31mIs dead\033[0m💀", time, idx);
			}
			return (1);
		}
		idx++;
	}
	return (0);
}
