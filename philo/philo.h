/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 04:06:57 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/15 06:43:16 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "color.h"

typedef struct s_time
{
	int					num_ph;
	int					max_meal;
	int					have_a_meal;
	int					bedtime;
	int					pass_away;
} t_time;

typedef struct philo
{
	pthread_t			th_philo;
	pthread_mutex_t		fork;	
	int					id_phi;
	t_time				*time;
} t_philo;

typedef struct env
{
	int					cur_id;
	bool				dead;
	t_time				time;
	t_philo				*philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*table;
} t_env;


int		parse_time(int ac, char **av, t_env *env);
int		print_error2(t_env *env);
int		print_error(void);
int		verify_av(char **av);
int		verify_digit(char n);
int		ft_atoi(const char *str);
int		space(char s);

#endif