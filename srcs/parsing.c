#include "../includes/philosophers.h"

int	add_number(char *data, int code)
{
	int	i;

	i = code;
	if (code == 1)
		= ft_atol(data[i]);
	if (code == 2)
		= ft_atol(data[i]);
	if (code == 3)
		= ft_atol(data[i]);
	if (code == 4)
		= ft_atol(data[i]);
	if (code == 5)
		= ft_ft_atol(data[i]);
}

int	parsing_init(char **data)
{
	int	i;

	i = 1;
	while (data[i] != NULL)
	{
		if (ft_atol(data[i]) == 0)
			return (FAIL);
		add_number(data[i], i);
		i++;
	}
	return (SUCCESS);
}