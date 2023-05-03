/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:56:47 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/04 04:34:06 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

	i = 1;
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if (verify_digit(av[i][j]) == 0)
			{
				printf("not digit , adios!\n");
				return(0);
			}
			j++;
		}
		i++;
	}
	return(1);
}

int main(int ac, char **av)
{

	if ((ac == 5 || ac == 6) && verify_av(av) == 1)
	{
		printf("ok and av is digit, (✿〇∀〇) let's go next!\n");
		if ()

	}
	else
	{
		printf("not enough av\n");
		if (verify_av(av) == 0)
			printf("av not digit\n");
		return(EXIT_FAILURE);
	}
}