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
	t_data			*data;
	t_pars			*pars;
	uint8_t			i;
	unsigned long	check;

	i = 0;
	data = (t_data *)args;
	pars = data->pars;
	data->dead = false;
	while (true)
	{
		while (i < pars->nb_philo)
		{
			check =  get_ms(data) - data->philo[i].last_meal;
			if (check > pars->time_die)
			{
				data->dead = true;
				printf("%u %d die 💀\n", get_ms(data), data->philo[i].id + 1);
				break ;
			}
			i++;
			check = 0;
		}
		if (data->dead)
			break ;
		i = 0;
	}
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