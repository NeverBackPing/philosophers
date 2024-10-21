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
# include <time.h>
# include <unistd.h>

# define FAIL 1
# define RED "\033[31mError:\033[0m"
# define EATS "\033[0;34mAll the philosophers have eaten\033[0;34m"
# define SUCCESS 0
# define STDERR 2
# define STDIN 0
# define STDOUT 1
# define ERR_THREAD "Error: failed to create thread\n"

/*Keep data during the parsing*/
typedef struct	t_philo_data
{
	/*Datas in milliseconds 1 sec = 1000 sec*/
	size_t			time_eat;
	size_t			life;
	size_t			time_sleep;
	size_t			time_think;
	size_t			nb_philo;
	size_t			nb_eat;
	t_thread_id		philo[200];
	pthread_mutex_t	write;
	int				philo_id;
	t_monitor		monitor;
}	t_philo_data;

typedef struct	t_monitor
{
	pthread_t		monitor;
	bool			dead;
	t_philo_data	philo_data;
} t_monitor;

typedef struct	t_thread_id
{
	//Philosophers
	pthread_t		philo; //threads
	int				philo_id; // i
	size_t			last_meal; // 0
	int				eating; // 0
	int				meals_eaten; // 0

	// un philo une fork
	size_t			nb_eat; // 0
	pthread_mutex_t	*fork; //init

	//Data input
	t_philo_data	datas;
}	t_thread_id;

//MAIN
int		malloc_mutex(t_thread_id *philo);
//Monitor
void	*manage(void *data);
int		monitor_threads(t_thread_id *philo);
//Parsing
int	parsing_init(char **data, t_philo_data *datas, t_thread_id *philo);
//Routines
int		ft_usleep(size_t milliseconds);
void	*routine(void *data);
//Utils
size_t	get_current_time ( void );
void	writer_error(char *message);
void	destroy_mutex(t_thread_id *philo);
int		malloc_mutex(t_thread_id *philo);
#endif