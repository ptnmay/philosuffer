/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 04:22:50 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/09 05:04:03 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_input(t_input *input, int ac, char **av)
{
	input->amount_ph = ft_atoi(av[1]);
	input->pass_away = ft_atoi(av[2]) * 1000;
	input->have_a_meal = ft_atoi(av[3]) * 1000;
	input->bedtime = ft_atoi(av[4]) * 1000;
	if (ac == 6)
		input->max_meal = ft_atoi(av[5]);
	else
		input->max_meal = 0;
	
}