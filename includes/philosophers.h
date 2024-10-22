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
# include <limits.h>
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

/*keep data inpout*/
typedef struct	t_pars
{
	/*Datas in milliseconds 1 sec = 1000 sec*/
	size_t			nb_philo;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			time_think;
	size_t			nb_eat;
}	t_pars;

/*struct for philo*/
typedef struct	t_philo
{
	int				id;
	long			last_meal;
	long			nb_meal;
	pthread_t 		philo;
	pthread_mutex_t	fork;

}	t_philo;

/*philo monitoring*/
typedef struct	t_monitor
{
	t_pars 			pars;
	t_data			data;
	pthread_t		monitor;
	bool			dead;
}	t_monitor;

/**/
typedef struct	t_data
{
	t_monitor		monitor;
	t_pars			pars;
	t_philo			philo[200];
	pthread_mutex_t	write;
	
}	t_data;

//Monitor
void	*manage(void *data);
int		monitor_threads(t_thread_id *philo);
//Parsing
long	ft_atol(const char *str);
bool	parsing_init(char **data, t_pars *pars);
//Routines
int		ft_usleep(size_t milliseconds);
void	*routine(void *data);
//Utils
size_t	get_current_time ( void );
void	writer_error(char *message);
#endif