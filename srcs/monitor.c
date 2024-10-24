/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:46:19 by sjossain          #+#    #+#             */
/*   Updated: 2024/10/21 13:46:19 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*manage(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	while (1)
	{
		
	}
	return (SUCCESS);
}

int	monitor_threads(t_data *data)
{
	data->dead = true;
	if (pthread_create(&data->monitor, NULL, manage, data))
		return (writer_error(ERR_THREAD), SUCCESS);
	if (pthread_join(data->monitor, NULL))
			return (SUCCESS);
	return (SUCCESS);
}