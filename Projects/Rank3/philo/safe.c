/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:20:03 by Jpedro-c          #+#    #+#             */
/*   Updated: 2025/02/25 12:20:04 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_mutex(t_mtx *mutex, t_code code)
{
	if (code == LOCK)
		mutex_error(pthread_mutex_lock(mutex), code);
	else if (code == UNLOCK)
		mutex_error(pthread_mutex_unlock(mutex), code);
	else if (code == INIT)
		mutex_error(pthread_mutex_init(mutex, NULL), code);
	else if (code == DESTROY)
		mutex_error(pthread_mutex_destroy(mutex), code);
	else
		error_exit("Wrong code for Mutex!");
}

void	mutex_error(int status, t_code code)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (code == UNLOCK || code == LOCK))
		error_exit("The value specified by mutex is invalid!");
	else if (status == EINVAL && code == INIT)
		error_exit("The value specified by attribute is invalid!");
	else if (status == EINVAL && code == DESTROY)
		error_exit("The value specified by attribute is invalid!");
	else if (status == EDEADLK)
		error_exit("A deadlockoccur in the thread blocked waiting for mutex!");
	else if (status == EPERM)
		error_exit("The current thread does not hold a lock on mutex!");
	else if (status == ENOMEM)
		error_exit("Cannot allocate enough memory to create another mutex!");
	else if (status == EBUSY)
		error_exit("Mutex is locked!");
}

void	s_thr(pthread_t *thread, void *(*ft)(void *), void *data, t_code code)
{
	if (code == CREATE)
		thread_error(pthread_create(thread, NULL, ft, data), code);
	else if (code == JOIN)
		thread_error(pthread_join(*thread, NULL), code);
	else if (code == DETACH)
		thread_error(pthread_detach(*thread), code);
	else
		error_exit("Wrong code for thread : Create / Join / Detach");
}

void	thread_error(int status, t_code code)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		error_exit("no resources to create another thread!");
	else if (status == EPERM)
		error_exit("The caller does not have permission!");
	else if (status == EINVAL && code == CREATE)
		error_exit("The value specified by attribute is invalid!");
	else if (status == EINVAL && (code == JOIN || code == DETACH))
		error_exit("The value specified by thread is not joinable!");
	else if (status == ESRCH)
		error_exit("No thread could be found with that id!");
	else if (status == EDEADLK)
		error_exit("Deadlock detected!");
}
