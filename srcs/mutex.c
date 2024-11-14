/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:46:25 by sjossain          #+#    #+#             */
/*   Updated: 2024/10/21 13:46:25 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	init_mutex_monitor(t_data *data)
{
	if (pthread_mutex_init(&data->write, NULL))
		return (writer_error(MUTEX_ERR), false);
	if (pthread_mutex_init(&data->update, NULL))
		return (writer_error(MUTEX_ERR), false);
	if (pthread_mutex_init(&data->lock, NULL))
		return (writer_error(MUTEX_ERR), false);
	if (pthread_mutex_init(&data->unlock, NULL))
		return (writer_error(MUTEX_ERR), false);
	return (true);
}

void	destroy_mutex_monitor(t_data *data)
{
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->update);
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->unlock);
}

bool	lock_fork_mutex(t_philo *philo, t_pars *pars)
{
	uint8_t	neighbor_pair_lock;
	uint8_t	neighbor_odd_lock;

	if (statut_thread(philo->data))
		return (true);
	pthread_mutex_lock(&philo->data->lock);
	if ((philo->id + 1) % 2 == 0)
	{
		neighbor_pair_lock = (philo->id + 1) % (pars->nb_philo);
		pthread_mutex_lock(&philo->data->philo[neighbor_pair_lock].fork);
		pthread_mutex_lock(&philo->data->philo[philo->id].fork);
	}
	else
	{
		neighbor_odd_lock = (philo->id + 1) % (pars->nb_philo);
		pthread_mutex_lock(&philo->data->philo[philo->id].fork);
		pthread_mutex_lock(&philo->data->philo[neighbor_odd_lock].fork);
	}
	if (statut_thread(philo->data))
	{
		unlock_fork_mutex(philo, pars);
		return (pthread_mutex_unlock(&philo->data->lock), true);
	}
	pthread_mutex_unlock(&philo->data->lock);
	return (false);
}

void	unlock_fork_mutex(t_philo *philo, t_pars *pars)
{
	uint8_t	neighbor_pair_unlock;
	uint8_t	neighbor_odd_unlock;

	pthread_mutex_lock(&philo->data->unlock);
	if ((philo->id + 1) % 2 == 0)
	{
		neighbor_pair_unlock = (philo->id + 1) % (pars->nb_philo);
		pthread_mutex_unlock(&philo->data->philo[philo->id].fork);
		pthread_mutex_unlock(&philo->data->philo[neighbor_pair_unlock].fork);
	}
	else
	{
		neighbor_odd_unlock = (philo->id + 1) % (pars->nb_philo);
		pthread_mutex_unlock(&philo->data->philo[neighbor_odd_unlock].fork);
		pthread_mutex_unlock(&philo->data->philo[philo->id].fork);
	}
	pthread_mutex_unlock(&philo->data->unlock);
}
