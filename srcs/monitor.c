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

void	*manage(void *args)
{
	t_thread_id *philo = (t_thread_id *)args;

	printf("name: %ld\n", philo->datas.nb_philo);
	while (1)
	{
		NULL;
	}
	return (SUCCESS);
}

int	monitor_threads(t_thread_id *philo)
{
	if (pthread_create(&philo->monitor, NULL, manage, &philo) != 0)
		return (writer_error(ERR_THREAD), SUCCESS);
	return (SUCCESS);
}