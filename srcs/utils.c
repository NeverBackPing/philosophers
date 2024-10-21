/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:46:29 by sjossain          #+#    #+#             */
/*   Updated: 2024/10/21 13:46:29 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


size_t	get_current_time ( void )
{
	struct  timeval 	time ;

	if (gettimeofday(&time, NULL ) == -1 )
		write( 2 , "gettimeofday() error\n" , 22 );
	return (time.tv_sec * 1000 + time.tv_usec / 1000 );
}

void	writer_error(char *message)
{
	size_t	len;

	len = 0;
	while (message[len] != '\0')
		len++;
	write(STDERR , message, len);
}

void	destroy_mutex(t_thread_id *philo)
{
	pthread_mutex_destroy(philo->write_lock);
	pthread_mutex_destroy(philo->dead_lock);
	pthread_mutex_destroy(philo->meal_lock);
	pthread_mutex_destroy(philo->l_fork);
	pthread_mutex_destroy(philo->r_fork);
}

int	malloc_mutex(t_thread_id *philo)
{
	philo->r_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (philo->r_fork == NULL)
		return (FAIL);
	philo->l_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (philo->l_fork == NULL)
		return (FAIL);
	philo->write_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (philo->write_lock == NULL)
		return (FAIL);
	philo->dead_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (philo->dead_lock == NULL)
		return (FAIL);
	philo->meal_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (philo->meal_lock == NULL)
		return (FAIL);
	return(SUCCESS);
}