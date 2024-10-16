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

void	add_number(char *data, int code, philo_data	*datas)
{
	if (code == 1)
		datas->nb_philo = ft_atol(data);
	if (code == 2)
		datas->life = ft_atol(data);
	if (code == 3)
		datas->time_eat = ft_atol(data);
	if (code == 4)
		datas->time_sleep = ft_atol(data);
	if (code == 5)
		datas->time_think = ft_atol(data);
	if (code == 6)
		datas->nb_eat = ft_atol(data);
}

int	parsing_init(char **data, philo_data *datas, thread_id *philo)
{
	size_t	i;

	i = 1;
	while (data[i] != NULL)
	{
		if (ft_atol(data[i]) <= 0)
			return (FAIL);
		add_number(data[i], i, datas);
		i++;
	}
	return (SUCCESS);
}
