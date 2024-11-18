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
	while (true)
	{
		if (statut_thread(data))
			break ;
		if (think(philo, data))
			break ;
		if (statut_thread(data))
			break ;
		if (eating(data, philo))
			break ;
		if (statut_thread(data))
			break ;
		if (sleeps(philo, data))
			break ;
	}
	/* pthread_mutex_lock(&data->write);
	printf("Thread: %p id: %d\n", &data->philo[philo->id].philo, data->philo[philo->id].id + 1);
	pthread_mutex_unlock(&data->write); */
	return (SUCCESS);
}
