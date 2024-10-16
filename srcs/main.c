/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:58:26 by sjossain          #+#    #+#             */
/*   Updated: 2024/10/15 18:58:26 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	philo_data	datas;
	thread_id	philo;
	thread_monitor	monitor;

	if (ac == 6 || ac == 5)
	{
		size_t	i;

		i = 0;
		pthread_mutex_init(&monitor.mutex, NULL);
		if (parsing_init(av, &datas, &philo))
		{
			printf("Error: invalide data\n");
			return (SUCCESS);
		}
		while (i++ < datas.nb_philo)
		{
			if (pthread_create(&philo.philo, NULL, routine, NULL) != 0)
				return (writer_error(ERR_THREAD), SUCCESS);
		}
		pthread_mutex_destroy(&monitor->mutex);
		monitor_threads(&monitor, &philo, &datas);
		pthread_join(&monitor.monitor, NULL);
		printf("%s", GREEN_MSG);
	}
	else
		printf("%s <./program philo life eat sleep think [plates]>\n", RED);
	return (SUCCESS);
}
