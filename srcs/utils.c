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

void	writer_error(char *message)
{
	unsigned int	len;

	len = 0;
	while (message[len] != '\0')
		len++;
	write(STDERR , message, len);
}

unsigned int	get_current_time (void)
{
	struct	timeval	time ;

	if (gettimeofday(&time, NULL ) == -1 )
		write(2 , "\033[31mError:\033[0m gettimeofday()\n" , 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}


unsigned int	get_ms(void)
{
	struct	timeval	start;
	struct	timeval	end;
	unsigned int	secs;
	unsigned int	usecs;

	gettimeofday(&start, NULL);
    gettimeofday(&end, NULL);
    secs  = end.tv_sec  - start.tv_sec;
    usecs = end.tv_usec - start.tv_usec;
	return (secs * 1000 + usecs / 1000 );
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
	printf(" ms: %u | Philo %d : I think 🏛️\n", get_current_time(), philo->id);
	pthread_mutex_unlock(&data->write);
	if (data->pars->nb_philo % 2 == 1)
		ft_usleep(data->pars->time_think);
}

bool	init_philo(t_philo *philo, uint8_t id, t_data *data, t_pars *pars)
{
	philo->id = id + 1;
	philo->last_meal = 0;
	philo->nb_meal = 0;
	if (pthread_mutex_init(&philo->fork, NULL))
		return (writer_error(MUTEX_ERR), false);
	philo->data = data;
	philo->pars = pars;
	return (true);
}
