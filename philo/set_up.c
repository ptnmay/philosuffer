/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 04:22:50 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/18 01:59:28 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_up_philo(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->data.num_ph)
	{
		PHILO[i].t_start = now();
		env->cur_id = i;
		pthread_create(&PHILO[i].th, NULL, routine, env);
		pthread_detach(PHILO[i].th);
		usleep(50);
		i += 2;
		if (i >= env->data.num_ph && i % 2 == 0)
			i = 1;
	}
	return (EXIT_SUCCESS);
}

int	set_up_fork(t_env *env)
{
	int	i;

	i = 0;
	env->forks = malloc(sizeof(pthread_mutex_t) * DATA.num_ph);
	if (!env->forks)
		return (EXIT_FAILURE);
	env->philo = (t_philo *)malloc(sizeof(t_philo) * DATA.num_ph);
	if (!env->philo)
		return (free(env->forks), EXIT_FAILURE);
	while (i < DATA.num_ph)
	{
		PHILO[i].id = i + 1;
		PHILO[i].myfork = i;
		PHILO[i].notmyfork = (i + 1) % DATA.num_ph;
		PHILO[i].th = NULL;
		pthread_mutex_init(&env->forks[i], NULL);
		PHILO[i].eat_cnt = 0;
		PHILO[i].checked = 0;
		PHILO[i].t_lastmeal = 0;
		PHILO[i].t_start = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	set_up_env(int ac, char **av, t_env *env)
{
	env->forks = NULL;
	env->philo = NULL;
	env->gone = 0;
	if (verify_av(av) == 0)
		return (EXIT_FAILURE);
	env->data.num_ph = ft_atoi(av[1]);
	env->data.gonetime = ft_atoi(av[2]);
	env->data.have_a_meal = ft_atoi(av[3]);
	env->data.bedtime = ft_atoi(av[4]);
	env->data.max = -1;
	if (ac == 6)
		env->data.max = ft_atoi(av[5]);
	env->table = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!env->table)
		return (EXIT_FAILURE);
	pthread_mutex_init(env->table, NULL);
	return (EXIT_SUCCESS);
}
