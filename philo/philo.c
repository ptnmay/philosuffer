/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:56:47 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/16 15:52:04 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_env	env;

	if (ac != 5 && ac != 6)
		return(philo_error(NULL));
	if (set_up_env(ac, av, &env))
		return(philo_error(&env));
	if (set_up_fork(&env))
		return(philo_error(&env));
	if (set_up_philo(&env))
		return(philo_error(&env));
	

	
	// printf("----here----\n");
}