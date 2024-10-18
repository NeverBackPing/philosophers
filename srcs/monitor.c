#include "../includes/philosophers.h"


//Keep time milliseconds
/*size_t	get_current_time ( void )
{
	struct  timeval 	time ;

	if (gettimeofday(&time, NULL ) == -1 )
		write( 2 , "gettimeofday() error\n" , 22 );
	return (time.tv_sec * 1000 + time.tv_usec / 1000 );
}*/

void	*manage(void *args)
{
	t_thread_id *philo = (t_thread_id *)args;
	printf("manage\n");
	pthread_join(philo->monitor, NULL);
	return (SUCCESS);
}

int	monitor_threads(t_thread_id *philo)
{
	if (pthread_create(&philo->monitor, NULL, manage, &philo) != 0)
				return (writer_error(ERR_THREAD), SUCCESS);
	return (SUCCESS);
}