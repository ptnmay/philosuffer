/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:56:47 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/16 05:00:22 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	// t_philo philo;
	
	// verify_input(ac, av, &philo);

	t_env	env;

	if ((ac != 5 || ac != 6) && verify_av(av) == 0)
		philo_error(NULL);
	if (set_up_env(ac, av, &env));
		philo_error(&env);
	if (set_up_philo(&env))
		philo_error(&env);

	
}