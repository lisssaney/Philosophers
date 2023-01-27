#include "ph1.h"

t_one	*one_info(t_philo *philo)
{
	int	i;

	philo->one = (t_one *)malloc((sizeof(t_one) * philo->number));
	i = 0;
	while (i < philo->number)
	{
		philo->one[i].order = i + 1;
		philo->one[i].philo1 = philo;
		philo->one[i].eat_last = get_time();
		philo->one[i].count = 0;
		philo->one[i].is_eating = -1;
		i++;
	}
	return (philo->one);
}

t_philo	*philo_args(int argc, char *argv[], t_philo *philo)
{
	philo->number = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->start = get_time();
	philo->number1 = 0;
	philo->died1 = 0;
	if (argc == 6)
		philo->eat_count = ft_atoi(argv[5]);
	else
		philo->eat_count = -1;
	return (philo);
}

t_philo	*philo_init(int argc, char *argv[])
{
	t_philo		*philo;
	int			i;

	i = -1;
	philo = NULL;
	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->number = ft_atoi(argv[1]);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_died");
	philo->forks = sem_open("/philo_forks", O_CREAT, S_IRWXU, philo->number);
	philo->died = sem_open("/philo_died", O_CREAT, S_IRWXU, 1);
	philo = philo_args(argc, argv, philo);
	philo->one = one_info(philo);
	one_threads(philo->one, philo->number);
	return (philo);
}
