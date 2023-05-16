/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 04:22:50 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/17 02:51:29 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *testroutine(void *env)
{
	(void)env;
	printf("hello philo\n");
	return(NULL);
}

int	set_up_philo(t_env *env)
{
	int i;

	i = 0;
	while(i < DATA.num_ph)
	{
		PHILO[i].t_start = now();
		env->cur_id = i;
		// pthread_create(&PHILO[i].th, NULL, testroutine, env);
		pthread_create(&PHILO[i].th, NULL, routine, env);
		pthread_detach(PHILO[i].th);
		usleep(100);
		i += 2;
		if (i >= DATA.num_ph && i % 2 == 0)
			i = 1;
	}
	return(EXIT_SUCCESS);
}

int	set_up_fork(t_env *env)
{
	int i;

	i = 0;
	env->forks = malloc(sizeof(pthread_mutex_t) * DATA.num_ph);
	if (!env->forks)
		return(EXIT_FAILURE);
	PHILO = malloc(sizeof(pthread_mutex_t) * DATA.num_ph);
	if (!PHILO)
		return(EXIT_FAILURE);
	while (i <= DATA.num_ph)
	{
		PHILO[i].id = i + 1;
		PHILO[i].myfork = i;
		PHILO[i].notmyfork = (i + 1) % DATA.num_ph;
		PHILO[i].th = NULL;
		pthread_mutex_init(&env->forks[i], NULL);
		PHILO[i].eat_cnt = 0;
		i++;
	}
	// i = 0;
	// while(i < 10)
	// {
	// 	printf("id == [%d]\n", PHILO[i].id);
	// 	printf("fork == [%d]\n", PHILO[i].myfork);
	// 	i++;

	// }

	return(EXIT_SUCCESS);
}

int	set_up_env(int ac, char **av, t_env *env)
{
	if (verify_av(av) == 0)
		return(EXIT_FAILURE);
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
	env->table = malloc(sizeof(pthread_t));
	if (!env->table)
		return (EXIT_FAILURE);
	pthread_mutex_init(env->table, NULL);
	// printf("philo == [%d]\n", DATA.num_ph);
	// printf("gone == [%d]\n", DATA.gonetime);
	// printf("eat == [%d]\n", DATA.have_a_meal);
	// printf("sleep == [%d]\n", DATA.bedtime);
	return(EXIT_SUCCESS);
}