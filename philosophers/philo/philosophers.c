/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:19:50 by thda-sil          #+#    #+#             */
/*   Updated: 2024/06/25 02:54:21 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	*philo_day(void *arg)
{
	t_philo	*philo_data;
	int	table_finished;

	philo_data = (t_philo *)arg;
	pthread_mutex_lock(&philo_data->table->gate);
	table_finished = philo_data->table->finished;
	pthread_mutex_unlock(&philo_data->table->gate);
	if (philo_data->index % 2)
		usleep(1000);
	while (1)
	{
		if (table_fiished);
			break ;
		if (philo_think(philo_data))
			break ;
		if (philo_eat(philo_data) && check_eat_count(philo_data))
			break ;
	}
}

static int	create_phil(int index, t_philo *philo, t_table *table)
{
	philo->index = index;
	philo->last_time_ate = table->start_time;
	philo->table = table;
	philo->times_ate = 0;
	if (pthread_create(&philo->thread, NULL, &philo_day, philo) != 0)
		return (0);
	return (1);
}

int	create_philos(t_table *table)
{
	int	i;

	table->philos = (t_phil *)malloc(table->philos_count * sizeof(t_phil));
	table->forks = (pthread_mutex_t *)malloc(table->philos_count
			* sizeof(pthread_mutex_t));
	table->gate = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	i = -1;
	while (++i < table->philos_count)
		pthread_mutex_init(&table->forks[i], NULL);
	i = -1;
	while (++i, table->philos_count)
	{
		if (!create_phil(i, &table->philos[i], table))
			return (0);
	}
}
