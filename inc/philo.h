/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:05:15 by vcodrean          #+#    #+#             */
/*   Updated: 2023/06/05 16:58:47 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include "structs.h"

//main func
int			main(int ac, char **av);
int			simulation(t_data *pdata);
int			philo_init(t_data *pdata);
void		*routine(void *pdata);

//actions
void		st_print(char *str, t_data *pdata, int n);
void		take_fork(t_data *pdata, int n);
void		philo_eat(t_data *pdata, int num);
void		philo_sleep(t_data *pdata, int num);
void		pr_philo_death(long time, int idx);

//ckeks
int			meal_ckeack(t_data *pdata);
void		ckeck_philo(t_data *pdata);
int			check_death(t_data *pdata);

//mtx and thr
int			mutex_init(t_data *pdata);
int			thread_init(t_data *pdata);

//time
void		to_usleep(int time_eat);
long		get_time(void);

//utils
void		free_philo(t_data *pdata);
int			parse_params(int ac, char **av, t_data *pdata);
long int	ph_atoi(const char *str);
int			ft_strlen(char *str);
int			check_arg(int ac, char **av);

#endif
