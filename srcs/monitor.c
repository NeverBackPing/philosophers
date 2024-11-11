/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:46:19 by sjossain          #+#    #+#             */
/*   Updated: 2024/10/21 13:46:19 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	destroy_mutex(t_data *data)
{
	uint8_t	i;

	i = 0;
	while (i < data->pars->nb_philo)
	{
		pthread_mutex_destroy(&data->philo[i].fork);
		i++;
	}
	destroy_mutex_monitor(data);
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

bool	monitor_threads(t_data *data, t_pars *pars)
{
	unsigned long	meal_check;
	uint8_t			i;

	i = 0;
	meal_check = 0;
	while (i < pars->nb_philo)
	{
		pthread_mutex_lock(&data->update);
		if (get_ms(data) - data->philo[i].last_meal > pars->time_die)
		{
			data->dead = true;
			pthread_mutex_lock(&data->write);
			printf("%u %d die 💀\n", get_ms(data), data->philo[i].id + 1);
			pthread_mutex_unlock(&data->write);
			pthread_mutex_unlock(&data->update);
			return (data->dead);
		}
		if (data->philo[i].nb_meal == data->pars->nb_eat)
			meal_check++;
		pthread_mutex_unlock(&data->update);
		i++;
	}
	pthread_mutex_lock(&data->update);
	if (meal_check == data->pars->nb_philo)
	{
		data->meal = true;
		pthread_mutex_unlock(&data->update);
		return (data->meal);
	}
	pthread_mutex_unlock(&data->update);
	return (false);
}

void	*monitor_routine(void *args)
{
	t_data	*data;
	t_pars	*pars;

	data = (t_data *)args;
	pars = data->pars;
	while (!(data->dead) || !(data->meal))
	{
		if (monitor_threads(data, pars))
		{
			break ;
		}
	}
	return (SUCCESS);
}


int	monitor(t_data *data)
{
	if (pthread_create(&data->monitor, NULL, monitor_routine, data))
		return (writer_error(ERR_THREAD), SUCCESS);
	join_thread(data);
	if (pthread_join(data->monitor, NULL))
			return (SUCCESS);
	return (SUCCESS);
}
