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

void	writer_error(char *message)
{
	unsigned int	len;

	len = 0;
	while (message[len] != '\0')
		len++;
	write(STDERR, message, len);
}

bool	init_program(t_data *data, t_pars *pars, char **av, int ac)
{
	if (ac != 5 && ac != 6)
		return (writer_error(E), FAIL);
	if (!parsing_init(av, pars, data))
		return (writer_error(DATA_ERR), FAIL);
	if (!(init_mutex_monitor(data)))
		return (FAIL);
	pars->start_time = 0;
	data->pars = pars;
	start_time(pars);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_pars	pars;
	t_data	data;
	uint8_t	i;

	if (init_program(&data, &pars, av, ac))
		return (FAIL);
	i = 0;
	while (i < pars.nb_philo)
	{
		if (!(init_philo(&data.philo[i], i, &data, &pars)))
		{
			join_thread(&data);
			return (destroy_mutex_monitor(&data), FAIL);
		}
		if (pthread_create(&data.philo[i].philo, NULL, routine, &data.philo[i]))
			return (writer_error(ERR_THREAD), FAIL);
		i++;
	}
	monitor(&data);
	join_thread(&data);
	destroy_mutex(&data);
	if ((data.dead) && !(data.meal))
		return (FAIL);
	return (printf("%s\n", EATS), SUCCESS);
}
