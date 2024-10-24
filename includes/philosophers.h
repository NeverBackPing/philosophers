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
typedef struct	s_pars
{
	/*Datas in milliseconds 1 sec = 1000 sec*/
	uint8_t							nb_philo;
	unsigned int					time_die; //change en unsigned long tout
	unsigned int					time_eat;
	unsigned int					time_sleep;
	unsigned int					time_think;
	unsigned int					nb_eat;
}	t_pars;

/*struct for philo*/
typedef struct	s_philo
{
	uint8_t				id;
	long			last_meal;
	long			nb_meal;
	pthread_t		philo;
	pthread_mutex_t	fork;
	t_data			*data;
	t_pars			*pars;
}	t_philo;

/*philo monitoring*/
typedef struct	s_data
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
void			*manage(void *data);
int				monitor_threads(t_data *data);
//Parsing
long			ft_atol(const char *str);
bool			parsing_init(char **argv, t_pars *pars, t_data *data);
//Routines
int				ft_usleep(unsigned int milliseconds);
void			*routine(void *data);
//Utils
bool			init_philo(t_philo *philo, uint8_t id, t_data *data, t_pars *pars);
unsigned int	get_current_time ( void );
void			writer_error(char *message);
void			join_thread(t_data	*data);
#endif