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


/* void init_philo(t_philo_data *philo,int i)
{
	philo->id = i;
	philo->time_die = philo->philo.
} */

int	main(int ac, char **av)
{
	//t_philo			philo;
	t_pars			pars;
	/*t_pars			data;
	t_monitor		monitor; */

	if (ac == 6 || ac == 7)
	{
		//size_t	i;

		//i = 0;
		if (parsing_init(av, &pars))
			return (printf("\033[31mError:\033[0m Invalide data\n"), SUCCESS);
		printf("philo : %ld | time_to_die : %ld | time_to_eat : %ld |  time_to_sleep : %ld | time_to_think : %ld | meal : %ld\n", pars.nb_philo,  pars.time_die, pars.time_eat, pars.time_sleep, pars.time_think, pars.nb_eat);
		/*if (pthread_mutex_init(&philo.fork, NULL))
			return (printf("Error: pthread_mutex_init\n"), SUCCESS);
		//monitor_threads(&philo);
		while (i++ < (size_t)ft_atol(av[1]))
		{
			//add 
			philo.philo[i] = {ft_atol(av[2]), ft_atol(av[3]), ft_atol(av[4]), ft_atol(av[5]), ft_atol(av[6])};
			if (pthread_create(&philo.philo[i], NULL, routine, &philo))
				return (writer_error(ERR_THREAD), SUCCESS);
		}
		if (pthread_join(monitor.monitor, NULL));
			return (SUCCESS);
		pthread_mutex_destroy(&philo.fork);*/
		printf("%s\n", EATS);
	}
	else
		printf("%s <./program philo life eat sleep think [plates]>\n", RED);
	return (SUCCESS);
}
