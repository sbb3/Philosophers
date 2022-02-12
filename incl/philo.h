/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:02:37 by adouib            #+#    #+#             */
/*   Updated: 2022/02/11 18:45:04 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define AVAILABLE 1
# define NOT_AVAILABLE 0
# define START 1
# define STOP 0
# define EATING 1
# define NOT_EATING 0

typedef struct s_philo
{
	int				id;
	int				philo_status;
	int				philo_eat_count;
	long			last_meal;
	int				left_fork;
	int				right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	pthread_mutex_t	*locks;
	int				*forks;
	pthread_mutex_t	display_lock;
	pthread_mutex_t	eat_lock;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philos_max_eat;
	long			start_time;
	int				simulation_begin;
	int				count;
	int				max_eats;
	int				notepme_argument;

	struct s_philo	*philos;
}	t_data;

void	display_status(t_philo *philo, int philo_num, char *s);
int		is_dead_yet(t_data *data, int i);
int		eat_count(t_data *data, int i);
int		odd_philos(int id);
int		ft_atoi(const char *s);

long	get_time(void);
long	timestamp_im_ms(t_philo *philo);
long	timepassed_im_ms(t_data *data);
void	ft_sleep(int time);

int		parser(const char *av[], t_data *data);
int		alloc(t_data *data);
void	init(t_data *data);
int		thread_handler(t_data *data);
void	watcher(t_data *data);
void	clear(t_data *data);

void	*philosopher(void *philo_number);
void	taking_up_forks(int philo_num, t_philo *philo);
void	eating(int philo_num, t_philo *philo);
void	puting_down_forks(t_philo *philo);

#endif
