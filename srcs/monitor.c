#include "../includes/philosophers.h"

void	*manage(void *args)
{
	t_thread_id *philo = (t_thread_id *)args;
	pthread_join(philo->monitor, NULL);
	return (SUCCESS);
}

int	monitor_threads(t_thread_id *philo)
{
	if (pthread_create(&philo->monitor, NULL, manage, &philo) != 0)
				return (writer_error(ERR_THREAD), SUCCESS);
	return (SUCCESS);
}