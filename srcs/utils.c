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


void	sleeps(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->write);
	if ((data->dead) || (data->meal))
	{
		pthread_mutex_unlock(&data->write);
		return ;
	}
	printf("%u %d is sleeping 😴\n", get_ms(philo->data), philo->id + 1);
	pthread_mutex_unlock(&data->write);
	ft_usleep(data->pars->time_sleep);
}

void	think(t_philo *philo, t_data *data)
{
	uint8_t	id;


	pthread_mutex_lock(&data->write);
	if ((data->dead) || (data->meal))
	{
		pthread_mutex_unlock(&data->write);
		return ;
	}
	id = philo->data->philo[philo->id].id + 1;
	printf("%u %d is thinking 🏛️\n", get_ms(data), id);
	pthread_mutex_unlock(&data->write);
	if (!(data->pars->nb_philo % 2 == 0))
		ft_usleep(data->pars->time_think);
}

bool	eating(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->write);
	lock_fork_mutex(philo, data->pars);
	//pthread_mutex_lock(&data->write);
	if (data->dead)
	{
		unlock_fork_mutex(philo, data->pars);
		return (true);
	}
	//pthread_mutex_unlock(&data->write);
	printf("%u %d has taken a fork 🍴\n", get_ms(philo->data), philo->id + 1);
	printf("%u %d has taken a fork 🍴\n", get_ms(philo->data), philo->id + 1);
	printf("%u %d is eating 🍜\n", get_ms(philo->data), philo->id + 1);
	pthread_mutex_lock(&data->meal_mutex);
	philo->data->philo[philo->id].last_meal= get_ms(philo->data);
	if (philo->data->pars->nb_eat != philo->data->philo[philo->id].nb_meal)
		philo->data->philo[philo->id].nb_meal++;
	pthread_mutex_unlock(&data->meal_mutex);
	unlock_fork_mutex(philo, data->pars);
	pthread_mutex_unlock(&data->write);
	ft_usleep(data->pars->time_eat);
	return (false);
}
