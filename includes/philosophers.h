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
# include <stdint.h>
# include <stdio.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define FAIL 1
# define SUCCESS 0
# define MUTEX_ERR "\033[31mError:\033[0m pthread_mutex_init\n"
# define DATA_ERR "\033[31mError:\033[0m Invalide data\n"
# define E "\033[31mError:\033[0m program philo life eat sleep think [meal]\n"
# define EATS "\033[0;34mAll the philosophers have eaten\033[0m"
# define STDERR 2
# define STDIN 0
# define STDOUT 1
# define ERR_THREAD "\033[31mError:\033[0m failed to create thread\n"

typedef struct s_data	t_data;
typedef struct s_pars
{
	uint8_t			nb_philo;
	unsigned long	time_die;
	unsigned long	time_eat;
	unsigned long	time_sleep;
	unsigned long	time_think;
	unsigned long	nb_eat;
	unsigned long	base;
	unsigned int	start_time;
}	t_pars;

/*struct for philo*/
typedef struct s_philo
{
	uint8_t			id;
	unsigned long	last_meal;
	unsigned long	nb_meal;
	pthread_t		philo;
	pthread_mutex_t	fork;
	t_data			*data;
	t_pars			*pars;
}	t_philo;

/*philo monitoring*/
typedef struct s_data
{
	pthread_t		monitor;
	bool			dead;
	bool			meal;
	t_philo			philo[200];
	t_pars			*pars;
	pthread_mutex_t	write;
	pthread_mutex_t	update;
	pthread_mutex_t	unlock;
	pthread_mutex_t	lock;
}	t_data;
//Main
bool			init_program(t_data *data, t_pars *pars, char **av, int ac);
void			writer_error(char *message);
//Monitor
bool			meal_thread(t_data *data, unsigned long meal_check);
bool			monitor(t_data *data);
bool			monitor_threads(t_data *data, t_pars *pars);
//Mutex
void			destroy_mutex_monitor(t_data *data);
bool			lock_fork_mutex(t_philo *philo, t_pars *pars);
bool			init_mutex_monitor(t_data *data);
void			unlock_fork_mutex(t_philo *philo, t_pars *pars);
//Parsing
bool			parsing_init(char **argv, t_pars *pars);
//Routines
bool			init_philo(t_philo *philo, uint8_t id, t_data *data,	\
				t_pars *pars);
void			*routine(void *data);
//threads
void			destroy_mutex(t_data *data);
void			join_thread(t_data	*data);
bool			statut_thread(t_data *data);
//Time
int				ft_usleep(unsigned int milliseconds, t_data *data);
unsigned int	get_ms(t_data *data);
unsigned int	get_current_time(void);
void			start_time(t_pars *pars);
//Utils
bool			eating(t_data *data, t_philo *philo);
bool			sleeps(t_philo *philo, t_data *data);
bool			think(t_philo *philo, t_data *data);
#endif