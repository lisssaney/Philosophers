#include "ph1.h"

void	exit_program(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->number)
	{
		pthread_mutex_destroy(&philo->forks[i]);
		pthread_mutex_destroy(&philo->one[i].eat);
	}
	free(philo->forks);
	pthread_mutex_destroy(&philo->died);
	free(philo->one);
	free(philo);
}

int	error_checker(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				printf("%s\n", "cannot use this symbol");
				return (0);
			}
		}
	}
	if (ft_atoi(argv[1]) == 1)
	{
		printf("%s\n", "not enough philosofers");
		return (0);
	}
	return (1);
}
