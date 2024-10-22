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


void init_philo(t_philo_data *philo,int i)
{
	philo->id = i;
	philo->time_die = philo->philo.
}

int	main(int ac, char **av)
{
	t_philo			philo;
	t_pars			pars;
	t_pars			data;
	t_monitor		monitor;

	if (ac == 6 || ac == 5)
	{
		size_t	i;

		i = 0;
		if (parsing_init(av, &datas, &philo))
			return (printf("Error: invalide data\n"), SUCCESS);
		//if (pthread_mutex_init(&philo.fork, NULL))
			//return (printf("Error: pthread_mutex_init\n"), SUCCESS);
		//monitor_threads(&philo);
		while (i++ < (size_t)ft_atol(av[1]))
		{
			philo.philo[i] = {ft_atol(av[2]), ft_atol(av[3]), ft_atol(av[4]), ft_atol(av[5]), ft_atol(av[6])};
			/* if (pthread_create(&philo.philo[i], NULL, routine, &philo{,,,,}))
				return (writer_error(ERR_THREAD), SUCCESS); */
		}
		printf("ID: %ld | die : %ld | eat : %ld | sleep : %ld | meat : %ld\n",philo.datas[0].id, philo.datas[0].time_die ,  philo.datas[0].time_eat, philo.datas[0].time_sleep , philo.datas[0].time_think, philo.datas[0].nb_eat);
		printf("ID: %ld | die : %ld | eat : %ld | sleep : %ld | meat : %ld\n",philo.datas[1].id,  philo.datas[1].time_die ,  philo.datas[1].time_eat, philo.datas[1].time_sleep , philo.datas[1].time_think, philo.datas[1].nb_eat);
		if (pthread_join(monitor.monitor, NULL));
			return (SUCCESS);
		pthread_mutex_destroy(&philo.fork);
		printf("%s\n", EATS);
	}
	else
		printf("%s <./program philo life eat sleep think [plates]>\n", RED);
	return (SUCCESS);
}
