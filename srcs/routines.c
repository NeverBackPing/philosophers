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

void	*routine(void *args)
{
	size_t	i;
	t_data	*data;

	i = 0;
	data = (t_data *)args;
	printf("AAAAAAAAAAAAAAAAAAA\n");
	/*while (1)
	{
		pthread_mutex_lock(philo->write_lock);
		pthread_mutex_unlock(philo->write_lock);
	}*/
	while (i++ < data->pars.nb_philo)
		pthread_join(data->philo[i].philo, NULL);
	return (SUCCESS);
}