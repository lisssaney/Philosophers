#ifndef PH1_H
# define PH1_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <semaphore.h>
# include <signal.h>

struct	s_philo;

typedef struct s_one
{
	int					order;
	struct s_philo		*philo1;
	unsigned long		eat_last;
	pthread_mutex_t		*lfork;
	pthread_mutex_t		*rfork;
	unsigned long		start1;
	pthread_mutex_t		eat;
	pthread_mutex_t		died;
	pid_t				id;
	int					is_eating;
	int					count;
}				t_one;

typedef struct s_philo
{
	sem_t					*forks;
	sem_t					*died;
	int						number;
	unsigned long			time_to_die;
	unsigned long			time_to_sleep;
	unsigned long			time_to_eat;
	unsigned long			start;
	int						number1;
	t_one					*one;
	int						died1;
	int						eat_count;
}				t_philo;

int				ft_isdigit(int c);
long unsigned	get_time(void);
void			wait_for(long unsigned time);
int				ft_atoi(char *str);
t_one			*one_info(t_philo *philo);
t_philo			*philo_args(int argc, char *argv[], t_philo *philo);
t_philo			*philo_init(int argc, char *argv[]);
int				check_death(t_one *one);
void			*checker(void *one1);
void			fork_mutex(t_one *one);
void			eat(t_one *one);
void			exit_program(t_philo *philo);
int				error_checker(char *argv[]);
int				main(int argc, char *argv[]);
int				one_threads(t_one *one, int numb);
void			*processes(void *one1);

#endif
