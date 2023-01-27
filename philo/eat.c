#include "ph1.h"

void	fork_mutex(t_one *one)
{
	if (one->order % 2 == 0)
		pthread_mutex_lock(one->rfork);
	else
		pthread_mutex_lock(one->lfork);
	printf("%lu %d %s\n", get_time() - one->philo1->start,
		one->order, "has taken a fork");
	if (one->order % 2 != 0)
		pthread_mutex_lock(one->rfork);
	else
		pthread_mutex_lock(one->lfork);
	printf("%lu %d %s\n", get_time() - one->philo1->start,
		one->order, "has taken a fork");
}

void	eat(t_one *one)
{
	fork_mutex(one);
	one->is_eating = 1;
	one->count += 1;
	one->eat_last = get_time();
	printf("%lu %d %s\n", get_time() - one->philo1->start,
		one->order, "is eating");
	wait_for(one->philo1->time_to_eat);
	one->is_eating = 0;
	pthread_mutex_unlock(&one->eat);
	pthread_mutex_unlock(one->rfork);
	pthread_mutex_unlock(one->lfork);
}
