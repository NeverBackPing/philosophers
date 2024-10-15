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
	thread_pid	philo;

	if (ac == 6 || ac == 5)
	{
		/* size_t	i;

		i = 0; */
		if (parsing_init(av, &datas, &philo))
		{
			printf("Error: invalide data\n");
			exit(SUCCESS);
		}
		/* while (i++ < datas.nb_philo)
			pthread_join(philo.philo, NULL); */
	}
	else
		printf("%s <./program philo life eat sleep think [plates]>\n", RED);
	exit(SUCCESS);
}