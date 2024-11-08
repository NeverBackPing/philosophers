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
	if (pthread_mutex_init(&data->meal_mutex, NULL))
		return (writer_error(MUTEX_ERR), false);
	return (true);
}

void	destroy_mutex_monitor(t_data *data)
{
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->meal_mutex);
}

void	lock_fork_mutex(t_philo *philo, t_pars *pars)
{
	uint8_t	neighbor_odd;
	uint8_t	neighbor_pair;

	if ((philo->id + 1) % 2 == 0)
	{
		neighbor_pair = (philo->id + 1) % (pars->nb_philo);
		pthread_mutex_lock(&philo->data->philo[neighbor_pair].fork);
		pthread_mutex_lock(&philo->data->philo[philo->id].fork);
	}
	else
	{
		neighbor_odd = (philo->id + 1) % (pars->nb_philo);
		pthread_mutex_lock(&philo->data->philo[philo->id].fork);
		pthread_mutex_lock(&philo->data->philo[neighbor_odd].fork);
	}
}

void	unlock_fork_mutex(t_philo *philo, t_pars *pars)
{
	uint8_t	neighbor_odd_unlock;
	uint8_t	neighbor_pair_unlock;

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
}
