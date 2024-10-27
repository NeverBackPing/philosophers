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


/* bool	philo_pair(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	while (true)
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(&philo->data->write);
			pthread_mutex_lock(&data->philo[philo->id - 1].fork);
			pthread_mutex_lock(&philo->fork);
			printf("Philo %d : take 🍴 philo %d\n", philo->id, data->philo[philo->id - 1].id);
			printf("Philo %d : I eating 🍜\n", philo->id);
			printf(" - - - - - - - - - -\n");
			pthread_mutex_unlock(&data->philo[philo->id - 1].fork);
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(&data->write);
			ft_usleep(philo->pars->time_eat);
			pthread_mutex_lock(&data->write);
			printf("Philo %d : I think 🏛️\n", philo->id);
			printf(" - - - - - - - - - -\n");
			pthread_mutex_unlock(&data->write);
			ft_usleep(philo->pars->time_think);
		}
		else
		{
			pthread_mutex_lock(&data->write);
			printf("Philo %d : I sleep 😴\n", philo->id);
			printf(" - - - - - - - - - -\n");
			pthread_mutex_unlock(&data->write);
			ft_usleep(philo->pars->time_sleep);
		}
		if (!(philo->id % 2 == 0))
		{
			pthread_mutex_lock(&philo->data->write);
			pthread_mutex_lock(&philo->fork);
			pthread_mutex_lock(&data->philo[philo->id + 1].fork);
			printf("Philo %d : take 🍴 philo %d\n", philo->id, data->philo[philo->id + 1].id);
			printf("Philo %d : I eating 🍜\n", philo->id);
			printf(" - - - - - - - - - -\n");
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(&data->philo[philo->id + 1].fork);
			pthread_mutex_unlock(&data->write);
			ft_usleep(philo->pars->time_eat);
			pthread_mutex_lock(&data->write);
			printf("Philo %d : I think 🏛️\n", philo->id);
			printf(" - - - - - - - - - -\n");
			pthread_mutex_unlock(&data->write);
			ft_usleep(philo->pars->time_think);
		}
		else
		{
			pthread_mutex_lock(&data->write);
			printf("Philo %d : I sleep 😴\n", philo->id);
			printf(" - - - - - - - - - -\n");
			pthread_mutex_unlock(&data->write);
			ft_usleep(philo->pars->time_sleep);
		}
	}
	return (true);
} */

/* bool	philo_odd(t_philo *philo)
{
	return (true);
} */

void	*routine(void *args)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)args;
	data = philo->data;
	while (true)
	{
		think(philo, data);
	}
	return (SUCCESS);
}