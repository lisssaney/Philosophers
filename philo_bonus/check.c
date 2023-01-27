#include "ph1.h"

int	check_death(t_one *one)
{
	if (one->is_eating == 0
		&& ((get_time() - one->eat_last) > one->philo1->time_to_die))
	{
		one->philo1->died1 += 1;
		if (one->philo1->died1 == 1)
			printf("%lu %d %s\n",
				get_time() - one->philo1->start, one->order, "DIED");
		return (0);
	}
	else if ((one->philo1->time_to_die < one->philo1->time_to_eat
			|| one->philo1->time_to_die < one->philo1->time_to_eat)
		&& get_time() - one->philo1->start >= one->philo1->time_to_die)
	{
		one->philo1->died1 += 1;
		if (one->philo1->died1 == 1)
			printf("%lu %d %s\n", get_time() - one->philo1->start,
				one->order, "DIED");
		return (0);
	}
	return (1);
}

void	*checker(void *one1)
{
	t_one	*one;

	one = (t_one *) one1;
	while (1)
	{
		if (check_death(one) == 0)
		{
			sem_post(one->philo1->died);
			exit(1);
		}
		if (one->philo1->number1 == one->philo1->number)
		{
			sem_post(one->philo1->died);
			exit(0);
		}
		usleep(1000);
	}
}
