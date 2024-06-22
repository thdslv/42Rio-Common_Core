/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:55:24 by thda-sil          #+#    #+#             */
/*   Updated: 2024/06/22 13:37:18 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <pthread.h>

#include <stdint.h>

typedef struct s_table t_table;

typedef struct s_phil
{
	int	index;
	int	times_ate;
	time_t	last_time_ate;
	t_table	*table;
	pthread_t	thread;
}		t_phil;

typedef struct s_table
{
	time_t	start_time;
	int		philos_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_times;
	int	finished_eating;
	pthread_mutex_t	gate;
	int	finished;
	pthread_t	vigilant;
	t_phil	*philos;
	pthread_mutex_t	*forks;
}				t_table;

// Philosophers
int	create_philos(t_table *table);

// Time
time_t		get_current_time(void);

#endif
