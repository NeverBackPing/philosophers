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

void	start_time(t_pars *pars)
{
	if (pars->start_time == 0)
		pars->start_time = get_current_time();
}

void	writer_error(char *message)
{
	unsigned int	len;

	len = 0;
	while (message[len] != '\0')
		len++;
	write(STDERR , message, len);
}

int	main(int ac, char **av)
{
	t_pars	pars;
	t_data	data;
	uint8_t	i;

	i = 0;
	if (ac != 5 && ac != 6)
		return (writer_error(E), FAIL);
	if (!parsing_init(av, &pars, &data))
		return (writer_error(DATA_ERR), FAIL);
	if (pthread_mutex_init(&data.write, NULL))
		return (writer_error(MUTEX_ERR), FAIL);
	start_time(&pars);
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
	if (monitor_threads(&data))
		return (SUCCESS);
	destroy_mutex(&data);
	if ((data.dead) && !(data.meal))
		return (FAIL);
	return (printf("%s\n", EATS), SUCCESS);
}
