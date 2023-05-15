/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 02:58:47 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/15 20:56:18 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error2(t_env *env)
{
	if (env)
		free(env);
	write(STDERR_FILENO, "SOMETHING WRONG\n", 17);
	return (EXIT_FAILURE);
}

int    print_error(void)
{
	printf("WRONG\n");
	return(EXIT_FAILURE);
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
        print_error();
	i = 1;
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if (verify_digit(av[i][j]) == 0)
                print_error();
			j++;
		}
		if (ft_atoi(av[i]) == 0)
			print_error();
		i++;
	}
	return(1);
}
