#include "../includes/philosophers.h"

void	*routine(thread_id	*philo, philo_data *datas)
{
	size_t	i;

	pthread_mutex_lock(&monitor->mutex);
	i = 0;
	printf("AHHAHAHAHAHAHAHAAHH\n");
	while (i++ < datas->nb_philo)
			pthread_join(philo->philo, NULL);
	pthread_mutex_unlock(&monitor->mutex);
	return (SUCCESS);
}