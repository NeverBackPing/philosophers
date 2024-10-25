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


void	philo_pair(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->data->write);
		pthread_mutex_lock(&philo->fork);
		if (philo->id % 2 == 0)
		{
			printf("philo %d : I eat \n", philo->id);
			ft_usleep(philo->pars->time_eat);
		}
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->data->write);
	}
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	/*pthread_mutex_lock(&philo->fork);
	pthread_mutex_unlock(&philo->fork);*/
	while (true)
	{
		if (philo->pars->nb_philo % 2 == 0)
		{
			//printf("philo %d: 🍜\n", philo->id);

		}
		else
		{
			//printf("philo %d : I sleep 😴\n", philo->id);
			ft_usleep(philo->pars->time_sleep);
		}
	}
	return (SUCCESS);
}