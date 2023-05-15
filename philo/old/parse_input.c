/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 04:22:50 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/16 00:49:35 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_input(t_philo *philo, int ac, char **av)
{
	(void)ac;
	printf("===================\n");
	philo->time.num_ph = ft_atoi(av[1]);
	philo->time.pass_away = ft_atoi(av[2]) * 1000;
	philo->time.have_a_meal = ft_atoi(av[3]) * 1000;
	philo->time.bedtime = ft_atoi(av[4]) * 1000;
	printf("===================\n");
	if (ac == 6)
		philo->time.max_meal = ft_atoi(av[5]);
	else
		philo->time.max_meal = -1;
	
}