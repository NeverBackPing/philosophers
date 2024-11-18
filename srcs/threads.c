/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:46:29 by sjossain          #+#    #+#             */
/*   Updated: 2024/10/21 13:46:29 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	statut_thread(t_data *data)
{
	pthread_mutex_lock(&data->update);
	if ((data->dead) || (data->meal))
	{
		pthread_mutex_unlock(&data->update);
		return (true);
	}
	pthread_mutex_unlock(&data->update);
	return (false);
}

bool	statut_thread_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->update);
	if ((data->dead) || (data->meal))
	{
		pthread_mutex_unlock(&data->write);
		unlock_fork_mutex(philo, data->pars);
		pthread_mutex_unlock(&data->update);
		return (true);
	}
	pthread_mutex_unlock(&data->update);
	return (false);
}

void	join_thread(t_data *data)
{
	uint8_t	i;

	i = 0;
	while (i < data->pars->nb_philo)
	{
		pthread_join(data->philo[i].philo, NULL);
		i++;
	}
}

void	destroy_mutex(t_data *data)
{
	uint8_t	i;

	i = 0;
	while (i < data->pars->nb_philo)
	{
		if (pthread_mutex_destroy(&data->philo[i].fork))
		{
			printf("HELLO destroy\n");
			printf("Thread: %p id: %d\n", &data->philo[i].philo, data->philo[i].id + 1);
		}
		i++;
	}
	destroy_mutex_monitor(data);
}
