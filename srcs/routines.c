/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:46:25 by sjossain          #+#    #+#             */
/*   Updated: 2024/10/21 13:46:25 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine(void *args)
{
	size_t	i;

	i = 0;
	t_thread_id *philo = (t_thread_id *)args;
	while (1)
	{
		//printf("Je verouille\n");
		pthread_mutex_lock(philo->write_lock);
		ft_usleep(philo->datas.time_sleep);
		//printf("liberer\n");
		pthread_mutex_unlock(philo->write_lock);
	}
	while (i++ < philo->datas.nb_philo)
		pthread_join(philo->philo, NULL);
	return (SUCCESS);
}