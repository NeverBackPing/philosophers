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


bool	philo_pair(t_philo *philo)
{
	while (true)
	{
		//pthread_mutex_lock(&philo->fork);
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(&philo->data->write);
			pthread_mutex_lock(&philo->data->philo[philo->id - 1].fork);
			pthread_mutex_lock(&philo->fork);
			printf("Philo %d : take 🍴 philo %d\n", philo->id, philo->data->philo[philo->id - 1].id);
			printf("Philo %d : I eating 🍜\n", philo->id);
			printf(" - - - - - - - - - -\n");
			pthread_mutex_unlock(&philo->data->philo[philo->id - 1].fork);
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(&philo->data->write);
			ft_usleep(philo->pars->time_eat);
			pthread_mutex_lock(&philo->data->write);
			printf("Philo %d : I think 🏛️\n", philo->id);
			printf(" - - - - - - - - - -\n");
			pthread_mutex_unlock(&philo->data->write);
			ft_usleep(philo->pars->time_think);
		}
		else
		{
			pthread_mutex_lock(&philo->data->write);
			printf("Philo %d : I sleep 😴\n", philo->id);
			printf(" - - - - - - - - - -\n");
			pthread_mutex_unlock(&philo->data->write);
			ft_usleep(philo->pars->time_sleep);
		}
		if (!(philo->id % 2 == 0))
		{
			pthread_mutex_lock(&philo->data->write);
			pthread_mutex_lock(&philo->fork);
			pthread_mutex_lock(&philo->data->philo[philo->id + 1].fork);
			printf("Philo %d : take 🍴 philo %d\n", philo->id, philo->data->philo[philo->id + 1].id);
			printf("Philo %d : I eating 🍜\n", philo->id);
			printf(" - - - - - - - - - -\n");
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(&philo->data->philo[philo->id + 1].fork);
			pthread_mutex_unlock(&philo->data->write);
			ft_usleep(philo->pars->time_eat);
			pthread_mutex_lock(&philo->data->write);
			printf("Philo %d : I think 🏛️\n", philo->id);
			printf(" - - - - - - - - - -\n");
			pthread_mutex_unlock(&philo->data->write);
			ft_usleep(philo->pars->time_think);
		}
		else
		{
			pthread_mutex_lock(&philo->data->write);
			printf("Philo %d : I sleep 😴\n", philo->id);
			printf(" - - - - - - - - - -\n");
			pthread_mutex_unlock(&philo->data->write);
			ft_usleep(philo->pars->time_sleep);
		}

		//pthread_mutex_unlock(&philo->fork);
	}
	return (true);
}

/*bool	philo_odd(t_philo *philo)
{
	return (true);
}*/

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (true)
	{
		if (philo->pars->nb_philo % 2 == 0 && !philo_pair(philo))
			break ;
		/*else if (philo->pars->nb_philo % 2 == 3 && !philo_odd(t_philo *philo))
			break ;*/
	}
	return (SUCCESS);
}