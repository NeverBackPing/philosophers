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
	uint8_t	i;

	i = 0;
	if (ac != 6 && ac != 7)
		return (writer_error(E), FAIL);
	if (!parsing_init(av, &pars, &data))
		return (writer_error(DATA_ERR), FAIL);
	if (pthread_mutex_init(&data.write, NULL))
		return (writer_error(MUTEX_ERR), FAIL);
	while (i < pars.nb_philo)
	{
		if (!init_philo(&data.philo[i], i, &data, &pars))
		{
			join_thread(&data);
			return (pthread_mutex_destroy(&data.write), FAIL);
		}
		if (pthread_create(&data.philo[i].philo, NULL, routine, &data.philo[i]))
			return (writer_error(ERR_THREAD), FAIL);
		i++;
	}
	destroy_mutex(&data);
	monitor_threads(&data);
	return (printf("%s\n", EATS), SUCCESS);
}
