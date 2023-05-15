/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 02:58:47 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/16 02:46:56 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_error(t_env *env)
{
	if (env)
		free_env(env);
	write(STDERR_FILENO, "Error\n", 7);
	return (EXIT_FAILURE);
}

int verify_digit(char n)
{
    if (n >= '0' && n <= '9')
        return(1);
    return(0);
}

int	verify_av(char **av)
{
	int i;
	int j;

    if (ft_atoi(av[1]) > 200)
        return(0);
	i = 1;
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if (verify_digit(av[i][j]) == 0)
	        	return(0);
			j++;
		}
		if (ft_atoi(av[i]) == 0)
        	return(0);
		i++;
	}
	return(1);
}