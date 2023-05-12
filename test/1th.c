/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1th.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:20:17 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/12 22:53:47 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *routine(void *n)
{
	printf("test from threads\n");
	printf("num = %d\n", *(int *)n);
	printf("-----------------------------\n");
	// sleep(3);
	*(int *)n += 1;
	printf("num = %d\n", *(int *)n);
	printf("ending threads\n");
	printf("-----------------------------\n");
	return(NULL);
}

int main(int ac, char **av)
{
	pthread_t t1, t2;
	int n = 12;
	// int *num = &n;
	if (pthread_create(&t1, NULL, &routine, &n) != 0)
		return(1);
	if (pthread_create(&t2, NULL, &routine, &n) != 0)
		return(2);
	if (pthread_join(t1, NULL) != 0)
		return(3);
	if (pthread_join(t2, NULL) != 0)
		return(4);
	return(0);
}