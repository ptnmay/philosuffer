/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 06:39:36 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/16 06:55:47 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	now(void)
{
	t_time	time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	present(long past)
{
	t_time	time;
	long	res;

	gettimeofday(&time, NULL);
	res = ((time.tv_sec * 1000) + (time.tv_usec / 1000)) - past;
	return(res);
}

int		wait_a_minute(long time, t_env *env)
{
	long	then;

	then =  now();
	while(!env->gone && present(then) < time)
		usleep(200);
	return(env->gone);
}