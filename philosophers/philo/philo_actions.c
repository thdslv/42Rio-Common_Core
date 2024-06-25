/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:38:57 by thda-sil          #+#    #+#             */
/*   Updated: 2024/06/25 02:56:18 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_think(t_philo *philo)
{
	int	table_finished;

	table_finished = 0;
	pthread_mutex_lock(&philo->table->gate);
	if (!philo->table->finished)
		printf("%ld %d thinking\n",
			get_formatted_time(philo->table->start_time), philo->index + 1);
	table_finish = philo->table->finished;
	pthread_mutex_unlock(&philo->table->gate);
	return (table_finish);
}

int	philo_eat(t_philo *philo)
{
	int	table_finish;
	int	forks[2];

	table_finish = 0;
	if (!get_forks(philo, forks))
		return (table_finish);
}
