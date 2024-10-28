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

typedef struct	s_data t_data;

/*keep data inpout*/
typedef struct		s_pars
{
	/*Datas in milliseconds 1 sec = 1000 sec*/
	uint8_t			nb_philo;
	unsigned long	time_die;
	unsigned long	time_eat;
	unsigned long	time_sleep;
	unsigned long	time_think;
	unsigned long	nb_eat;
	unsigned int	start_time;
}	t_pars;

/*struct for philo*/
typedef struct		s_philo
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
typedef struct		s_data
{
	//monitor philo
	pthread_t		monitor;
	bool			dead;
	//struct philo
	t_philo			philo[200];
	//data intput
	t_pars			*pars;
	//mange writing
	pthread_mutex_t	write;
}	t_data;
//Monitor
void			destroy_mutex(t_data *data);
void			join_thread(t_data	*data);
int				monitor_threads(t_data *data);
//Parsing
bool			parsing_init(char **argv, t_pars *pars, t_data *data);
//Routines
int				ft_usleep(unsigned int milliseconds);
void			*routine(void *data);
//Utils
unsigned int	get_ms(t_data *data);
void			start_time(t_data *data, t_pars *pars);
bool			init_philo(t_philo *philo, uint8_t id, t_data *data, t_pars *pars);
unsigned int	get_current_time ( void );
void			think(t_philo *philo, t_data *data);
void			writer_error(char *message);
#endif