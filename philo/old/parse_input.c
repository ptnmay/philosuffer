/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 04:22:50 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/09 21:57:10 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_input(t_time *time, int ac, char **av)
{
	time->amount_ph = ft_atoi(av[1]);
	time->pass_away = ft_atoi(av[2]) * 1000;
	time->have_a_meal = ft_atoi(av[3]) * 1000;
	time->bedtime = ft_atoi(av[4]) * 1000;
	if (ac == 6)
		time->max_meal = ft_atoi(av[5]);
	else
		time->max_meal = 0;
	
}