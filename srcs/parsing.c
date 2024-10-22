/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:15:34 by sjossain          #+#    #+#             */
/*   Updated: 2024/10/15 19:15:34 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	ft_atol(const char *str)
{
	long	number;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		number = number * 10 + (str[i++] - '0');
	}
	return (number * sign);
}


bool	init_data(char *data, int code, t_pars *pars)
{
	if (code == 1)
	{
		pars->nb_philo = ft_atol(data);
		if (pars->nb_philo > 200)
			return (true);
	}
	if (code == 2)
		pars->time_die = ft_atol(data);
	if (code == 3)
		pars->time_eat = ft_atol(data);
	if (code == 4)
		pars->time_sleep = ft_atol(data);
	if (code == 5)
		pars->time_think = ft_atol(data);
	if (code == 6)
		pars->nb_eat = ft_atol(data);
	return (false);
}

bool	parsing_init(char **data, t_pars *pars)
{
	size_t	i;

	i = 1;
	while (data[i] != NULL)
	{
		if (ft_atol(data[i]) <= 0)
			return (true);
		if (init_data(data[i], i, pars))
			return (true);
		i++;
		if (data[i] == NULL && i == 6)
			pars->nb_eat = 0;
	}
	return (false);
}

