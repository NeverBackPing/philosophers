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

int	malloc_mutex(t_thread_id *philo)
{
	philo->r_fork = allocate_mutex();
	if (philo->r_fork == NULL)
		return (FAIL);
	philo->l_fork = allocate_mutex();
	if (philo->l_fork == NULL)
		return (FAIL);
	philo->write_lock = allocate_mutex();
	if (philo->write_lock == NULL)
		return (FAIL);
	philo->dead_lock = allocate_mutex();
	if (philo->dead_lock == NULL)
		return (FAIL);
	philo->meal_lock = allocate_mutex();
	if (philo->meal_lock == NULL)
		return (FAIL);
	return(SUCCESS);
}

int	main(int ac, char **av)
{
	t_philo_data	datas;
	t_thread_id		philo;

	if (ac == 6 || ac == 5)
	{
		size_t	i;

		i = 0;
		if (parsing_init(av, &datas))
			return (printf("Error: invalide data\n"), SUCCESS);
		if (malloc_mutex(&philo))
			return (SUCCESS);
		if (pthread_mutex_init(philo.write_lock, NULL))
			printf("Error: pthread_mutex_init\n");
		while (i < datas.nb_philo)
		{
			if (pthread_create(&philo.philo, NULL, routine, &philo) != 0)
				return (writer_error(ERR_THREAD), SUCCESS);
			pthread_join(philo.philo, NULL);
			i++;
		}
		monitor_threads(&philo);
		pthread_mutex_destroy(philo.write_lock);
		//pthread_mutex_destroy(philo.dead_lock);
		//pthread_mutex_destroy(philo.meal_lock);
		//pthread_mutex_destroy(philo.l_lock);
		//pthread_mutex_destroy(philo.r_lock);
		printf("%s", EATS);
	}
	else
		printf("%s <./program philo life eat sleep think [plates]>\n", RED);
	return (SUCCESS);
}
