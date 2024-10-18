#include "../includes/philosophers.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	writer_error(char *message)
{
	write(STDERR , message, ft_strlen(message));
}

pthread_mutex_t	*allocate_mutex(void)
{
	return ((pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)));
}