/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:10:25 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/18 02:40:24 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlockf(t_env *env, int id)
{
	if (env->gone
		|| pthread_mutex_unlock(&env->forks[env->philo[id].myfork]))
		return ;
	if (env->gone
		|| pthread_mutex_unlock(&env->forks[env->philo[id].notmyfork]))
		return ;
}

void	thefork(t_env *env, int id)
{
	printf(THK, GRN, present(env->philo[id].t_start), id + 1, RESET);
	if (env->gone || pthread_mutex_lock(&env->forks[env->philo[id].myfork]))
		return ;
	printf(MYF, YEL, present(env->philo[id].t_start), id + 1, RESET);
	if (env->gone || pthread_mutex_lock(&env->forks[env->philo[id].notmyfork]))
		return ;
	printf(NOTMY, MAG, present(env->philo[id].t_start), id + 1, RESET);
	printf(EAT, BLU, present(env->philo[id].t_start), id + 1, RESET);
}

void	*routine(void *en)
{
	t_env	*env;
	int		id;

	env = (t_env *)en;
	id = env->cur_id;
	env->philo[id].id = id;
	env->philo[id].t_lastmeal = env->philo[id].t_start;
	while (!env->gone && (env->philo[id].eat_cnt < env->data.max
			|| env->data.max == -1))
	{
		thefork(env, id);
		env->philo[id].t_lastmeal = now();
		if (wait_a_minute(env->data.have_a_meal, env))
			return (NULL);
		unlockf(env, id);
		++env->philo[id].eat_cnt;
		if (env->philo[id].eat_cnt == env->data.max)
			return (NULL);
		printf(BED, WHT, present(env->philo[id].t_start), id + 1, RESET);
		if (wait_a_minute(env->data.bedtime, env))
			return (NULL);
	}
	return (NULL);
}
