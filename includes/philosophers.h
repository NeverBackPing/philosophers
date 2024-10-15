/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:14:51 by sjossain          #+#    #+#             */
/*   Updated: 2024/10/15 19:14:51 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <fcntl.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

# define FAIL 1
# define RED "\033[31mError:\033[0m"
# define SUCCESS 0
# define STDERR 2
# define STDIN 0
# define STDOUT 1

/*Keep data during the parsing*/
typedef struct	philo_data
{
	/*Datas in milliseconds 1 sec = 1000 sec*/
	size_t	time_eat;
	size_t	life;
	size_t	time_sleep;
	size_t	time_think;
	size_t	nb_philo;
	size_t	nb_eat;
}	philo_data;

//NOTE:
/* Faire un monitor un autre thread pour
 dire aux autres qu'un philosophe est mort*/

typedef struct	thread_pid
{
	pthread_t	philo;
}	thread_pid;

int		parsing_init(char **data, philo_data *datas, thread_pid *hilo);

#endif