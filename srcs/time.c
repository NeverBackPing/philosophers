/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:46:25 by sjossain          #+#    #+#             */
/*   Updated: 2024/10/21 13:46:25 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	start_time(t_pars *pars)
{
	if (pars->start_time == 0)
		pars->start_time = get_current_time();
}

unsigned int	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL ) == -1)
		write(2, "\033[31mError:\033[0m gettimeofday()\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

unsigned int	get_ms(t_data *data)
{
	unsigned int	current_time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (current_time - data->pars->start_time);
}

int	ft_usleep(unsigned int milliseconds)
{
	unsigned int	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
