/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 04:06:57 by psaeyang          #+#    #+#             */
/*   Updated: 2023/05/18 02:36:14 by psaeyang         ###   ########.fr       */
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
	int				num_ph;
	int				gonetime;
	int				have_a_meal;
	int				bedtime;
	int				max;
}	t_data;

typedef struct s_philo
{
	pthread_t			th;
	int					id;
	time_t				t_start;
	time_t				t_lastmeal;
	int					myfork;
	int					notmyfork;
	int					eat_cnt;
	int					checked;
}	t_philo;

typedef struct s_env
{	
	int					cur_id;
	bool				gone;
	t_data				data;
	t_philo				*philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*table;
}	t_env;

# define THK		"%s%ld %d is thinking%s\n"
# define MYF		"%s%ld %d has taken fork%s\n"
# define NOTMY		"%s%ld %d has taken fork%s\n"
# define EAT		"%s%ld %d is eating%s\n"
# define BED		"%s%ld %d is sleeping%s\n"
# define BYE		"%s%ld %d is die%s\n"

int		ft_atoi(const char *str);
int		wait_a_minute(long time, t_env *env);
int		philo_error(t_env *env);
int		set_up_env(int ac, char **av, t_env *env);
int		set_up_fork(t_env *env);
int		verify_av(char **av);
int		set_up_philo(t_env *env);
long	present(long past);
long	now(void);
void	*routine(void	*en);
void	free_env(t_env *env);
void	free_philo(t_env *env);
void	verify_dead(t_env *env);

#endif
