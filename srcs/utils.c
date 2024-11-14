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

bool	sleeps(t_philo *philo, t_data *data)
{
	if (statut_thread(data))
		return (true);
	pthread_mutex_lock(&data->write);
	printf("%u %d is sleeping 😴\n", get_ms(philo->data), philo->id + 1);
	pthread_mutex_unlock(&data->write);
	if (data->pars->time_die < data->pars->time_sleep)
		return (true);
	ft_usleep(data->pars->time_sleep);
	if (statut_thread(data))
		return (true);
	return (false);
}

/*if (!(data->pars->nb_philo % 2 == 0))
{
if (data->pars->time_die < data->pars->base)
return (true);
ft_usleep(data->pars->time_think);
}*/
bool	think(t_philo *philo, t_data *data)
{
	uint8_t	id;

	if (statut_thread(data))
		return (true);
	pthread_mutex_lock(&data->write);
	id = philo->data->philo[philo->id].id + 1;
	printf("%u %d is thinking 🏛️\n", get_ms(data), id);
	pthread_mutex_unlock(&data->write);
	return (false);
}

bool	eating(t_data *data, t_philo *philo)
{
	if (statut_thread(data) || data->pars->nb_philo == 1)
		return (true);
	if (lock_fork_mutex(philo, data->pars))
		return (true);
	pthread_mutex_lock(&data->write);
	printf("%u %d has taken a fork 🍴\n", get_ms(philo->data), philo->id + 1);
	printf("%u %d has taken a fork 🍴\n", get_ms(philo->data), philo->id + 1);
	printf("%u %d is eating 🍜\n", get_ms(philo->data), philo->id + 1);
	pthread_mutex_unlock(&data->write);
	unlock_fork_mutex(philo, data->pars);
	pthread_mutex_lock(&data->update);
	philo->data->philo[philo->id].last_meal = get_ms(philo->data);
	if (philo->data->pars->nb_eat != philo->data->philo[philo->id].nb_meal)
		philo->data->philo[philo->id].nb_meal++;
	pthread_mutex_unlock(&data->update);
	if (data->pars->time_die < data->pars->time_eat)
		return (true);
	ft_usleep(data->pars->time_eat);
	if (statut_thread(data))
		return (true);
	return (false);
}
