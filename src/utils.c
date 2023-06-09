/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:04:08 by vcodrean          #+#    #+#             */
/*   Updated: 2023/06/01 12:54:48 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ph_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	nbr = nbr * sign;
	if (nbr > 2147483647)
		return (-1);
	return (nbr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_arg(int ac, char **av)
{
	int	num;
	int	i;

	num = 1;
	while (num < ac)
	{
		i = 0;
		if (av[num][i] == '+' && (ft_strlen(av[num]) > 1))
			i++;
		while (av[num][i])
		{
			if (av[num][i] < '0' || av[num][i] > '9')
				return (0);
			i++;
		}
		num++;
	}
	return (1);
}
