/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:27:36 by thda-sil          #+#    #+#             */
/*   Updated: 2024/07/12 16:30:05 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

/*
	Text formating
*/
# define  RESET "\033[0m"
# define  RED "\033[1;31m"
# define  GREEN "\033[1;32m"
# define  YELLOW "\033[1;33m"
# define  BLUE "\033[1;34m"
# define  MAGENTA "\033[1;35m"
# define  CYAN "\033[1;36m"
# define  WHITE "\033[1;37m"

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

/*
	Fork
*/
typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

/*
	Philo
	./philo 5 800 200 200 [5]
*/
typedef struct s_philo
{
	int		id;
	long	meals_counter;
	bool	full;
	long	last_meal_time;
	t_fork	*left_fork;
	t_fork	*right_fork;
	pthread_t	thread_id;
	t_table	*table;
}	t_philo;

/*
	Table
*/
typedef struct s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meals;
	long	start_simulation;
	bool	end_simulation;
	t_fork	*forks;
	t_philo	*philos;
}	t_table;

// Utils
void	error_exit(const char *error);

#endif
