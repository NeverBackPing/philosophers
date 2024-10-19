#include "../includes/philosophers.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	*routine(void *args)
{
	size_t	i;

	i = 0;
	t_thread_id *philo = (t_thread_id *)args;
	while (1)
	{
		//printf("Je verouille\n");
		pthread_mutex_lock(philo->write_lock);
		ft_usleep(philo->datas.time_sleep);
		//printf("liberer\n");
		pthread_mutex_unlock(philo->write_lock);
	}
	while (i++ < philo->datas.nb_philo)
		pthread_join(philo->philo, NULL);
	return (SUCCESS);
}