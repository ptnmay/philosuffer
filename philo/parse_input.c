/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 04:22:50 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/15 06:40:11 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_time(int ac, char **av, t_env *env)
{

	env->forks = NULL;
	printf("here\n");
	env->philo = NULL;
	env->dead = 0;
	env->time.num_ph = ft_atoi(av[1]);
	env->time.pass_away = ft_atoi(av[2]);
	env->time.have_a_meal = ft_atoi(av[3]);
	env->time.bedtime = ft_atoi(av[4]);
	if (ac == 6)
		env->time.max_meal = ft_atoi(av[5]);
	else
		env->time.max_meal = -1;
	env->table = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!env->table)
		return (EXIT_FAILURE);
	pthread_mutex_init(env->table, NULL);
	return (EXIT_SUCCESS);
}