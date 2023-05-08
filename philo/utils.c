/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 02:56:05 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/08 19:33:42 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int verify_digit(char n)
{
    if (n >= '0' && n <= '9')
        return(1);
    return(0);
}

int space(char s)
{
    if ((s >= 9 && s <= 13) || s == 32)
        return(1);
    return(0);
}

int	ft_atoi(const char *str)
{
    int i = 0;
    int res = 0;

    if (str[0] == '-' || str[0] == '+')
        i = 1;
    while(space(str[i]) == 1)
        i++;
    while(str[i] >= '0' && str[i] <= '9')
    {   
        while(space(str[i]) == 1)
            i++;
        if (str[i] == '-' || str[i] == '+')
            return(0);
        res = res * 10 + (str[i] - '0');
        i++;
    }
    if (str[0] == '-')
        return(res * -1);
    return(res);
}