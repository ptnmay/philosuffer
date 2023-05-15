/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 04:22:50 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/16 05:06:07 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_up_philo(t_env *env)
{
	int i;

	i = 0;
	// env->forks = malloc(sizeof(pthread_mutex_t) * env->time.num_ph);
	// if (!env->forks)
	// 	return(EXIT_FAILURE);
	PHILO = malloc(sizeof(pthread_mutex_t) * DATA.num_ph);
	if (!PHILO)
		return(EXIT_FAILURE);
	while (i < DATA.num_ph)
	{
		
	}
}

int	set_up_env(int ac, char **av, t_env *env)
{
	env->forks = NULL;
	PHILO = NULL;
	env->gone = 0;
	DATA.num_ph = ft_atoi(av[1]);
	DATA.gonetime = ft_atoi(av[2]);
	DATA.have_a_meal = ft_atoi(av[3]);
	DATA.bedtime = ft_atoi(av[4]);
	if (ac == 6)
		DATA.max_meal = ft_atoi(av[5]);
	else
		DATA.max_meal = -1;
	return(EXIT_SUCCESS);
}