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
		//Think
		think(philo, data);

		//Eat
		pthread_mutex_lock(&data->write);
		pthread_mutex_lock(&data->philo[philo->id + 1].fork);
		pthread_mutex_lock(&data->philo[philo->id].fork);
		eating(data, philo);
		pthread_mutex_unlock(&data->philo[philo->id].fork);
		pthread_mutex_unlock(&data->philo[philo->id + 1].fork);
		pthread_mutex_unlock(&data->write);

		//Sleep
		pthread_mutex_lock(&data->write);
		ft_usleep(data->pars->time_sleep);
		printf("%u %d is sleeping 😴\n", get_ms(data), philo->id + 1);
		pthread_mutex_unlock(&data->write);
	}
	return (SUCCESS);
}
