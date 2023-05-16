/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:10:25 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/17 05:10:59 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_count(t_env *env, int id)
{
	if (!(PHILO[id].eat_cnt < DATA.max_meal) && (!env->gone))
	{
		env->gone = 1;
		printf("%s%ld %d is die%s\n",RED, present(PHILO[id].t_start), id + 1, reset);
	}
}

void	unlock(t_env *env, int id)
{
	if (env->gone || pthread_mutex_unlock(&env->forks[env->philo[id].myfork]))
		return ;
	if (env->gone || pthread_mutex_unlock(&env->forks[env->philo[id].notmyfork]))
		return ;
}

void	lockthefork(t_env *env, int id)
{
	printf("%s%ld %d is thinking%s\n",GRN, present(PHILO[id].t_start), id + 1, reset);
	pthread_mutex_lock(env->table);
	if (env->gone || pthread_mutex_lock(&env->forks[env->philo[id].myfork]))
		return ;
	printf("%s%ld %d has taken fork%s\n",YEL, present(PHILO[id].t_start), id + 1, reset);
	if (env->gone || pthread_mutex_lock(&env->forks[env->philo[id].notmyfork]))
		return ;
	printf("%s%ld %d has taken fork%s\n",MAG, present(PHILO[id].t_start), id + 1, reset);
	pthread_mutex_unlock(env->table);
		printf("%s%ld %d is eating%s\n",BLU, present(PHILO[id].t_start), id + 1, reset);
}

void	*routine(void *en)
{
	t_env	*env;
	int		id;

	env = (t_env *)en;
	id = env->cur_id;
	PHILO[id].id = id;
	PHILO[id].t_lastmeal = PHILO[id].t_start;
	while(!env->gone && (PHILO[id].eat_cnt < DATA.max_meal || DATA.max_meal == -1))
	{
		lockthefork(env, id); //print thinking take fork
		PHILO[id].t_lastmeal = now();
		if (wait_a_minute(DATA.have_a_meal, env))
			return(NULL);
		unlock(env, id);
		++PHILO[id].eat_cnt;
		if (PHILO[id].eat_cnt == DATA.max_meal)
			return(NULL);
		printf("%s%ld %d is sleeping%s\n",WHT, present(PHILO[id].t_start), id + 1, reset);
		if (wait_a_minute(DATA.bedtime, env))
			return(NULL);
	}
	eat_count(env, id);
	return(NULL);
}