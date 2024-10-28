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

bool	init_philo(t_philo *philo, uint8_t id, t_data *data, t_pars *pars)
{
	philo->id = id;
	philo->last_meal = 0;
	philo->nb_meal = 0;
	if (pthread_mutex_init(&philo->fork, NULL))
		return (writer_error(MUTEX_ERR), false);
	philo->data = data;
	philo->pars = pars;
	return (true);
}

void	*routine(void *args)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)args;
	data = philo->data;
	start_time(data, philo->pars);
	while (true)
	{
		think(philo, data);
		pthread_mutex_lock(&data->write);
		pthread_mutex_lock(&data->philo[philo->id + 1].fork);
		printf("%u %d has taken a fork 🍴\n", get_ms(data), philo->id);
		pthread_mutex_lock(&data->philo[philo->id].fork);
		printf("%u %d has taken a fork 🍴\n", get_ms(data), philo->id);
		printf("%u %d is eating 🍜\n", get_ms(data), philo->id);
		ft_usleep(data->pars->time_eat);
		pthread_mutex_unlock(&data->write);
		pthread_mutex_lock(&data->write);
		ft_usleep(data->pars->time_sleep);
		printf("%u %d is sleeping 😴\n", get_ms(data), philo->id + 1);
		pthread_mutex_unlock(&data->write);
	}
	return (SUCCESS);
}
