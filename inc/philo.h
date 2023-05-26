/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:05:15 by vcodrean          #+#    #+#             */
/*   Updated: 2023/05/26 18:44:00 by vcodrean         ###   ########.fr       */
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

int			main(int ac, char **av);
int			parse_params(int ac, char **av, t_data *data);

//utils
long int	ph_atoi(const char *str);
int			ft_strlen(char *str);
int         check_arg(int ac, char **av);

//core functions
int			simulation(t_data *pdata);
int			philo_init(t_data *pdata);
void		*routine(void *d);
int         thread_init(t_data *pdata);

//actions
void    take_fork(t_data *pdata, int n);
void    st_print(char *str, t_data *pdata, int n);
void    philo_eat(t_data *pdata, int num);
void    philo_sleep(t_data *pdata, int num);


//mutex
int			mutex_init(t_data *pdata);

//time func's 
long		get_time(void);
void	    to_usleep(int time_eat);

//chekers
int check_death(t_data *pdata);
int meal_ckeack(t_data *pdata);

#endif
