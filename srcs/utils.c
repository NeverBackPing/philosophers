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

unsigned int	get_current_time (void)
{
	struct	timeval	time ;

	if (gettimeofday(&time, NULL ) == -1 )
		write(2 , "\033[31mError:\033[0m gettimeofday()\n" , 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}


unsigned int	get_ms(t_data *data)
{
	struct timeval	time;
	unsigned int	current_time;
	gettimeofday(&time, NULL);

	current_time = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (current_time - data->pars->start_time);
}

int	ft_usleep(unsigned int milliseconds)
{
	unsigned int	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	think(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->write);
	if (data->dead)
	{
		pthread_mutex_unlock(&data->write);
		return ;
	}
	printf("%u %d is thinking 🏛️\n", get_ms(data), philo->id + 1);
	pthread_mutex_unlock(&data->write);
	if (data->pars->nb_philo % 2 == 1)
		ft_usleep(data->pars->time_think);
}

void	eating(t_data *data, t_philo *philo, uint8_t i)
{
	if (data->dead)
		return ;
	printf("%u %d has taken a fork 🍴\n", get_ms(data), philo->id + 1);
	printf("%u %d has taken a fork 🍴\n", get_ms(data), philo->id + 1);
	printf("%u %d is eating 🍜\n", get_ms(data), philo->id + 1);
	data->philo[i].nb_meal++;
	data->philo[i].last_meal = get_ms(data);
	ft_usleep(data->pars->time_eat);
	//printf("last: %lu id : %d\n", data->philo[i].last_meal, i + 1);
}
