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
	t_pars	pars;
	t_data	data;
	size_t	i;

	if (ac == 6 || ac == 7)
	{
		i = 1;
		if (parsing_init(av, &pars))
			return (printf("%s Invalide data\n", RED), SUCCESS);
		if (pthread_mutex_init(&data.write, NULL))
			return (printf("%s pthread_mutex_init\n", RED), SUCCESS);
		while (i++ < pars.nb_philo + 1)
		{
			init_philo(data.philo[i], i);
			if (pthread_create(&data.philo[i].philo, NULL, routine, &data))
				return (writer_error(ERR_THREAD), SUCCESS);
		}
		monitor_threads(&data);
		pthread_mutex_destroy(&data.write);
		printf("%s\n", EATS);
	}
	else
		printf("%s <./program philo life eat sleep think [plates]>\n", RED);
	return (SUCCESS);
}
