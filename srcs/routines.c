#include "../includes/philosophers.h"

void	*routine(void *args)
{
	t_thread_id *philo = (t_thread_id *)args;

	usleep(1);
	printf("Je verouille\n");
	pthread_mutex_lock(&philo->mutex);
	printf("HEllo\n");
	pthread_mutex_unlock(&philo->mutex);
	printf("liberer\n");
	return (SUCCESS);
}