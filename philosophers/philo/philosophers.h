/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:55:24 by thda-sil          #+#    #+#             */
/*   Updated: 2024/06/19 01:59:00 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_table t_table;

typedef struct s_philosopher
{
	int	index;
	int	eat_count;
	time_t	last_time_ate;
	t_table	*table;
	pthread_t	thread;
}		t_philosopher;

typedef struct s_table
{
	time_t	start_time;
	int		philos_count;
	int	time_to_die;
	int	time_to_sleep;
	int	time_to_eat;
	int	must_eat_times;
	int	finished_eating;
	pthread_mutex_t	gate;
	int	finished;
	pthread_t	vigilant;
	t_philo	*philos;
	pthread_mutex_t	*forks;
}				t_table;



#endif
