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


size_t	get_current_time ( void )
{
	struct  timeval 	time ;

	if (gettimeofday(&time, NULL ) == -1 )
		write( 2 , "gettimeofday() error\n" , 22 );
	return (time.tv_sec * 1000 + time.tv_usec / 1000 );
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	writer_error(char *message)
{
	size_t	len;

	len = 0;
	while (message[len] != '\0')
		len++;
	write(STDERR , message, len);
}

bool	init_philo(t_philo philo, int identifier)
{
	philo.id = identifier;
	philo.last_meal = 0;
	philo.nb_meal = 0;
	if (pthread_mutex_init(&philo.fork, NULL))
			return (printf("%s pthread_mutex_init\n", RED), true);
	return (false);
}
