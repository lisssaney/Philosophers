#include "ph1.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long unsigned	get_time(void)
{
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	return (actual.tv_sec * 1000 + actual.tv_usec / 1000);
}

void	wait_for(long unsigned time)
{
	long unsigned	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

int	ft_atoi(char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 0;
	c = 1;
	if (str[a] == '\0')
		return (0);
	while (str[a] == '\n' || str[a] == '\r' || str[a] == '\t'
		|| str[a] == '\v' || str[a] == ' ' || str[a] == '\f')
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			c = -c;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
		b = (b * 10) + (str[a++] - 48);
	return (b * c);
}
