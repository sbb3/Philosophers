/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:11:51 by adouib            #+#    #+#             */
/*   Updated: 2022/02/11 17:59:05 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	puting_down_forks(int id, t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->locks[PHILO_FORK]);
	philo->data->forks[PHILO_FORK] = AVAILABLE;
	pthread_mutex_unlock(&philo->data->locks[NEXT_PHILO_FORK]);
	philo->data->forks[NEXT_PHILO_FORK] = AVAILABLE;
}

void	eating(int id, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_lock);
	philo->philo_status = EATING;
	if (!philo->data->forks[PHILO_FORK] && !philo->data->forks[NEXT_PHILO_FORK])
		display_status(philo, id, "%ld ms Philo %d is eating\n");
	pthread_mutex_unlock(&philo->data->eat_lock);
	philo->philo_status = NOT_EATING;
	philo->last_meal = timestamp_im_ms(philo);
	philo->philo_eat_count++;
	philo->data->count++;
	ft_sleep(philo->data->time_to_eat);
}

void	taking_up_forks(int id, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->locks[NEXT_PHILO_FORK]);
	philo->data->forks[NEXT_PHILO_FORK] = NOT_AVAILABLE;
	display_status(philo, id, "%ld ms Philo %d has taken a fork\n");
	pthread_mutex_lock(&philo->data->locks[PHILO_FORK]);
	philo->data->forks[PHILO_FORK] = NOT_AVAILABLE;
	display_status(philo, id, "%ld ms Philo %d has taken a fork\n");
}

void	*philosopher(void *args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
	if (odd_philos(philo->id))
		usleep(1500);
	while (philo->data->simulation_begin == START)
	{
		taking_up_forks(philo->id, philo);
		eating(philo->id, philo);
		puting_down_forks(philo->id, philo);
		display_status(philo, philo->id, "%ld ms Philo %d is sleeping\n");
		ft_sleep(philo->data->time_to_sleep);
		display_status(philo, philo->id, "%ld ms Philo %d is thinking\n");
	}
	return (NULL);
}

int	thread_handler(t_data *data)
{
	int	i;
	int	err;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		err = pthread_create(&data->tid[i], 0, philosopher, &data->philos[i]);
		if (err != 0)
			return (write(1, "Error! cannot create a thread\n", 31));
	}
	return (0);
}
