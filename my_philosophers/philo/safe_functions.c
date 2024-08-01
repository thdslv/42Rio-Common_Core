/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:50:11 by thda-sil          #+#    #+#             */
/*   Updated: 2024/07/31 19:35:57 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
		error_exit("Malloc failed");
	return (ret);
}

static void	handle_mutex_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (opcode == LOCK
			|| opcode == UNLOCK || opcode == DESTROY))
		error_exit("The value specified by mutex is invalid.");
	else if (status == EINVAL && opcode == INIT)
		error_exit("The value specified by attr is invalid.");
	else if (status == EDEADLK)
		error_exit("A deadlock would occur if the thread "
			"blocked waiting for mutex");
	else if (status == EPERM)
		error_exit("The current thread does not hold a lock on mutex");
	else if (status == ENOMEM)
		error_exit("The process cannot allocate enough memory to "
			"create another mutex");
	else if (status == EBUSY)
		error_exit("The mutex is locked");
}

/*
	Safe mutex
	init
	destroy
	lock
	unlock
*/
void	safe_mutex_hndle(t_mtx *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		pthread_mutex_lock(mutex);
	else if (opcode == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (opcode == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (opcode == DESTROY)
		pthread_mutex_destroy(mutex);
	else
		error_exit("Wrong opcode for mutex handle");
}
