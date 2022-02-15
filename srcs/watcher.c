/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:17:30 by adouib            #+#    #+#             */
/*   Updated: 2022/02/15 17:28:47 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	eat_count(t_data *data, int i)
{
	if (data->philos[i].philo_eat_count == data->philos_max_eat \
		&& data->count == data->max_eats)
	{
		data->simulation_begin = STOP;
		return (1);
	}
	return (0);
}

int	is_dead_yet(t_data *data, int i)
{
	if (((get_time() - data->start_time) - data->philos[i].last_meal) \
		>= data->time_to_die && !data->philos[i].philo_status)
	{
		data->simulation_begin = STOP;
		printf("%ld ms Philo %d died\n", \
			timepassed_im_ms(data), data->philos[i].id);
		return (1);
	}
	return (0);
}

void	watcher(t_data *data)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->number_of_philosophers)
		{
			if (is_dead_yet(data, i))
				return ;
			if (data->notepme_argument && eat_count(data, i))
				return ;
		}
	}
}
