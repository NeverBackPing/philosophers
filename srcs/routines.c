#include "../includes/philosophers.h"

void	*routine(void *args)
{
	t_thread_id *philo = (t_thread_id *)args;

	usleep(1);
	printf("Je verouille\n");
	pthread_mutex_lock(philo->write_lock);
	printf("HEllo\n");
	pthread_mutex_unlock(philo->write_lock);
	printf("liberer\n");
	return (SUCCESS);
}