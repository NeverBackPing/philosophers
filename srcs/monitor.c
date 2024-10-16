#include "../includes/philosophers.h"

void	*manage(thread_id *philo, philo_data *datas)
{
	return (SUCCESS);
}

int	monitor_threads(thread_monitor	*monitor, thread_id	*philo, philo_data *datas)
{
	if (pthread_create(monitor->monitor, NULL, manage, NULL) != 0)
				return (writer_error(ERR_THREAD), SUCCESS);
	return (SUCCESS);
}