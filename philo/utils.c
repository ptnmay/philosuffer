/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 02:56:05 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/18 02:07:33 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	verify_dead(t_env *env)
{
	int	id;
	int	cnt;

	id = 0;
	cnt = 0;
	while (!env->gone && cnt != DATA.num_ph)
	{
		if (id >= DATA.num_ph)
			id = 0;
		if (PHILO[id].eat_cnt >= DATA.max
			&& !PHILO[id].checked && DATA.max != -1)
		{
			cnt++;
			PHILO[id].checked = 1;
		}
		else if (present(PHILO[id].t_lastmeal) > env->data.gonetime)
		{
			env->gone = 1;
			printf(BYE, RED, present(PHILO[id].t_start), id + 1, RESET);
			printf("%s（┛〃°　Д°）┛\n%s", BCYN, RESET);
			return ;
		}
		usleep(10);
		id++;
	}
}

void	tamlaimutex(t_env *env)
{
	int	i;

	i = 0;
	verify_dead(env);
	pthread_mutex_destroy(env->table);
	while (i < env->data.num_ph)
	{
		pthread_mutex_destroy(&env->forks[i]);
		i++;
	}
}

void	free_philo(t_env *env)
{
	tamlaimutex(env);
	free(env->forks);
	free(env->philo);
	free(env->table);
}

void	free_env(t_env *env)
{
	int	i;

	i = 0;
	if (env->forks)
		free(env->forks);
	if (env->philo)
	{
		while (i < env->data.num_ph && PHILO[i].th)
		{
			free(PHILO[i].th);
			i++;
		}
		free(env->philo);
	}
}
