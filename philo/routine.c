/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:10:25 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/18 02:01:32 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thefork(t_env *env, int id)
{
	printf(THK, GRN, present(env->philo[id].t_start), id + 1, RESET);
	if (env->gone || pthread_mutex_lock(&env->forks[env->philo[id].myfork]))
		return ;
	printf(MYF, YEL, present(PHILO[id].t_start), id + 1, RESET);
	if (env->gone || pthread_mutex_lock(&env->forks[PHILO[id].notmyfork]))
		return ;
	printf(NOTMY, MAG, present(PHILO[id].t_start), id + 1, RESET);
	printf(EAT, BLU, present(PHILO[id].t_start), id + 1, RESET);
}

void	*routine(void *en)
{
	t_env	*env;
	int		id;

	env = (t_env *)en;
	id = env->cur_id;
	PHILO[id].id = id;
	PHILO[id].t_lastmeal = PHILO[id].t_start;
	while (!env->gone && (PHILO[id].eat_cnt < DATA.max || DATA.max == -1))
	{
		thefork(env, id);
		PHILO[id].t_lastmeal = now();
		if (wait_a_minute(DATA.have_a_meal, env))
			return (NULL);
		if (env->gone || pthread_mutex_unlock(&env->forks[PHILO[id].myfork]))
			return (NULL);
		if (env->gone || pthread_mutex_unlock(&env->forks[PHILO[id].notmyfork]))
			return (NULL);
		++PHILO[id].eat_cnt;
		if (PHILO[id].eat_cnt == DATA.max)
			return (NULL);
		printf(BED, WHT, present(PHILO[id].t_start), id + 1, RESET);
		if (wait_a_minute(DATA.bedtime, env))
			return (NULL);
	}
	return (NULL);
}
