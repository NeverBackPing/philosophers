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
	int8_t	i;
	int8_t	sign;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
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

uint8_t	ft_atoi_uint8(const char *str)
{
	uint8_t			number;
	unsigned int	i;

	i = 0;
	number = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number > (UINT8_MAX / 10) ||
			(number == (UINT8_MAX / 10) && (str[i] - '0') > (UINT8_MAX % 10)))
			return (0);
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number);
}

bool	parsing_init(char **argv, t_pars *pars)
{
	pars->nb_philo = ft_atoi_uint8(argv[1]);
	pars->time_die = ft_atol(argv[2]);
	pars->time_eat = ft_atol(argv[3]);
	pars->time_sleep = ft_atol(argv[4]);
	pars->time_think = ft_atol(argv[5]);
	if (argv[6] == NULL)
		pars->nb_eat = -1;
	else
		pars->nb_eat = ft_atol(argv[6]);
	if (pars->nb_philo <= 0 || pars->nb_philo > 200)
		return (false);
	if (pars->time_die <= 0 || pars->time_eat <= 0 || pars->time_sleep <= 0
	|| pars->time_think <= 0)
		return (false);
	return (true);
}
