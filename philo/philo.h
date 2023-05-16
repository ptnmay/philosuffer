/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 04:06:57 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/17 06:29:45 by psaeyang         ###   ########.fr       */
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

typedef struct timeval	t_time;

typedef struct s_data
{
	int					num_ph;
	int					have_a_meal;
	int					bedtime;
	int					gonetime;
	int					max_meal;
} t_data;

typedef struct philo
{
	pthread_t			th;
	long				t_start;
	long				t_lastmeal;
	int					id;
	int					myfork;
	int					notmyfork;
	int					eat_cnt;
	int					checked;

} t_philo;

typedef struct s_env
{	
	int				cur_id;
	bool			gone;
	t_philo			*philo;
	t_data			data;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*table;
}	t_env;

# define PHILO		env->philo
# define DATA		env->data

void    verify_input(int ac, char **av, t_philo *philo);
int		set_up_env(int ac, char **av, t_env *env);
int		set_up_fork(t_env *env);
int		philo_error(t_env *env);
int		verify_av(char **av);
int		verify_digit(char n);
int		ft_atoi(const char *str);
int		space(char s);
long	present(long past);
int		wait_a_minute(long time, t_env *env);
long	now(void);
int		set_up_philo(t_env *env);
void	*routine(void *en);
void	free_env(t_env *env);
void    free_philo(t_env *env);

#endif