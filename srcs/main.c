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
	t_philo_data	datas;
	t_thread_id		philo;

	if (ac == 6 || ac == 5)
	{
		size_t	i;

		i = 0;
		if (parsing_init(av, &datas, &philo))
			return (printf("Error: invalide data\n"), SUCCESS);
		if (malloc_mutex(&philo))
			return (SUCCESS);
		if (pthread_mutex_init(philo.write_lock, NULL))
			printf("Error: pthread_mutex_init\n");
		monitor_threads(&philo);
		while (i++ < datas.nb_philo)
		{
			philo.philo_id++;
			if (pthread_create(&philo.philo, NULL, routine, &philo) != 0)
				return (writer_error(ERR_THREAD), SUCCESS);
		}
		if (pthread_join(philo.monitor, NULL));
			return (SUCCESS);
		destroy_mutex(&philo);
		printf("%s", EATS);
	}
	else
		printf("%s <./program philo life eat sleep think [plates]>\n", RED);
	return (SUCCESS);
}
