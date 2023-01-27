#include "ph1.h"

void	exit_program(t_philo *philo)
{
	int	i;
	int	j;
	int	f;

	i = -1;
	while (++i < philo->number)
	{
		waitpid(-1, &f, 0);
		if (f != 0)
		{
			j = -1;
			while (++j < philo->number)
				kill(philo->one[j].id, 15);
			break ;
		}
	}
	sem_close(philo->died);
	sem_close(philo->forks);
	sem_unlink("/philo_died");
	sem_unlink("/philo_forks");
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
