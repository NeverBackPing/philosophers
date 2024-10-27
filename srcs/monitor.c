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
	pthread_mutex_destroy(&data->write);
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

void	*monitor(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	while (true)
	{
	}
		printf("manage : %d\n", data->dead);
	return (SUCCESS);
}

int	monitor_threads(t_data *data)
{
	data->dead = true;
	if (pthread_create(&data->monitor, NULL, monitor, data))
		return (writer_error(ERR_THREAD), SUCCESS);
	join_thread(data);
	if (pthread_join(data->monitor, NULL))
			return (SUCCESS);
	return (SUCCESS);
}