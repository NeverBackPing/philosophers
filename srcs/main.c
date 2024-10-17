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
		if (pthread_mutex_init(&philo.mutex, NULL))
			printf("Error: pthread_mutex_init\n");
		if (parsing_init(av, &datas))
			return (printf("Error: invalide data\n"), SUCCESS);
		while (i < datas.nb_philo)
		{
			if (pthread_create(&philo.philo, NULL, routine, &philo) != 0)
				return (writer_error(ERR_THREAD), SUCCESS);
			pthread_join(philo.philo, NULL);
			i++;
		}
		monitor_threads(&philo);
		pthread_mutex_destroy(&philo.mutex);
		printf("%s", EATS);
	}
	else
		printf("%s <./program philo life eat sleep think [plates]>\n", RED);
	return (SUCCESS);
}
