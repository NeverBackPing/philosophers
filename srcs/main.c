#include "../includes/philosophers.h"

int	main(int ac, char **av, char **envp)
{
	if (ac == 6 || ac == 5)
	{
		if (parsing_init(av))
			exit(SUCCESS);
	}
	else
		printf("Error: nb_philo time_life time_eat time_sleep [nb of plates]\n");
	exit(SUCCESS);
}