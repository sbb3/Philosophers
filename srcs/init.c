/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:20:02 by adouib            #+#    #+#             */
/*   Updated: 2022/02/11 14:20:03 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	init(t_data *data)
{
	int	i;

	data->start_time = get_time();
	data->simulation_begin = START;
	data->count = ZERO;
	data->max_eats = data->number_of_philosophers * data->philos_max_eat;
	pthread_mutex_init(&data->eat_lock, 0);
	pthread_mutex_init(&data->display_lock, 0);
	i = -1;
	while (++i < data->number_of_philosophers)
	{
		data->philos[i].data = data;
		data->philos[i].philo_eat_count = ZERO;
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = ZERO;
		data->philos[i].philo_status = NOT_EATING;
		data->forks[i] = AVAILABLE;
		pthread_mutex_init(&data->locks[i], 0);
	}
}
