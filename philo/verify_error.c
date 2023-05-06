/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 02:58:47 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/07 03:08:25 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_error(int n)
{
    if (n == 0)
        printf(RED"this input isn't enough, adios!\n");
    else if (n == 1)
        printf(RED"this input isn't digit, adios!\n");
    else if (n == 2)
        printf(RED"too many philosophers, adios!\n");
    // else if (n == 3)
    exit(0);
}

int	verify_av(char **av)
{
	int i;
	// int j;

    if (ft_atoi(av[1]) > 200)
        print_error(2);
	i = 1;
	while(av[i])
	{
		if (ft_atoi(av[i]) < 0)
            print_error(1);
		i++;
	}
	return(1);
	// while(av[i])
	// {
	// 	j = 0;
	// 	while(av[i][j])
	// 	{
	// 		if (verify_digit(av[i][j]) == 0)
    //             print_error(1);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// return(1);
}

void    verify_input(int ac, char **av)
{
    if ((ac == 5 || ac == 6) && verify_av(av) == 1)
	{
		printf(CYA"ok and av is digit, (✿〇∀〇) let's go next!\n");
	}
	else
		print_error(0);
}