/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 02:56:05 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/17 06:29:21 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    tamlaimutex(t_env *env)
{
    int	i;

    i = 0;
    pthread_mutex_destroy(env->table);
	while (i < DATA.num_ph)
	{
		pthread_mutex_destroy(&env->forks[i]);
		i++;
	}
}

void    verify_dead(t_env *env)
{
    int id;
    int cnt;

    id = 0;
    cnt = 0;
    while(!env->gone && (cnt != DATA.num_ph))
    {
        if (id >= DATA.num_ph)
            id = 0;
        if (PHILO[id].eat_cnt >= DATA.max_meal && !PHILO[id].checked && DATA.max_meal != -1)
        {
            cnt++;
            PHILO->checked = 1;
        }
        else if (present(PHILO[id].t_lastmeal) > DATA.gonetime)
        {
            env->gone = 1;
		    printf("%s%ld %d is die%s\n",RED, present(PHILO[id].t_start), id + 1, reset);
            return ;
        }
        id++;
    }
    tamlaimutex(env);
}

void	free_env(t_env *env)
{
	int	i;

	i = 0;
	if (env->forks)
		free(env->forks);
	if (env->philo)
	{
		while(i < DATA.num_ph && PHILO[i].th)
		{
			free(PHILO[i].th);
			i++;
		}
		free(env->philo);
	}
}

void    free_philo(t_env *env)
{
    verify_dead(env);
    free(env->forks);
	free(env->philo);
	free(env->table);
}