#include "ph1.h"

void	*processes(void *one1)
{
	t_one			*one;
	pthread_t		t1;

	one = (t_one *) one1;
	if (pthread_create(&t1, NULL, (void *) checker, one1))
		return ((void *) 1);
	pthread_detach(t1);
	while (1)
	{
		eat(one);
		if (one->count == one->philo1->eat_count)
			one->philo1->number1++;
		if (one->philo1->number1 == one->philo1->number)
		{
			pthread_mutex_unlock(&one->philo1->died);
			return ((void *) 0);
		}
		printf("%lu %d %s\n", get_time() - one->philo1->start,
			one->order, "is sleeping");
		wait_for(one->philo1->time_to_sleep);
		printf("%lu %d %s\n", get_time() - one->philo1->start,
			one->order, "is thinking");
	}
	return (NULL);
}

static	int	one_threads1(t_one *one, int numb)
{
	int	i;

	i = -1;
	while (++i < numb)
	{
		if (i % 2 != 0)
		{
			if (pthread_create(&one[i].tid, NULL, (void *) processes,
					(void *) &one[i]))
				return (1);
			pthread_detach(one[i].tid);
		}
		usleep(100);
	}
	return (0);
}

int	one_threads(t_one *one, int numb)
{
	int	i;

	i = -1;
	while (++i < numb)
	{
		if (i % 2 == 0)
		{
			if (pthread_create(&one[i].tid, NULL, (void *) processes,
					(void *) &one[i]))
				return (1);
			pthread_detach(one[i].tid);
		}
		usleep(100);
	}
	if (one_threads1(one, numb) == 1)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_philo	*philo;

	if (argc < 5 || argc > 6)
	{
		printf("%s\n", "wrong number of arguments");
		return (0);
	}
	if (error_checker(argv) == 0)
		return (0);
	philo = philo_init(argc, argv);
	pthread_mutex_lock(&philo->died);
	pthread_mutex_unlock(&philo->died);
	exit_program(philo);
	return (0);
}
