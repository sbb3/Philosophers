/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:01:27 by adouib            #+#    #+#             */
/*   Updated: 2022/02/11 17:01:28 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

long	get_time(void)
{
	struct timeval	tp;
	long			timestamp_in_ms;

	timestamp_in_ms = 0;
	gettimeofday(&tp, 0);
	timestamp_in_ms = tp.tv_sec * 1000;
	timestamp_in_ms += tp.tv_usec / 1000;
	return (timestamp_in_ms);
}

long	timestamp_im_ms(t_philo *philo)
{
	long	current_time;

	current_time = get_time() - philo->data->start_time;
	return (current_time);
}

long	timepassed_im_ms(t_data *data)
{
	long	current_time;

	current_time = get_time() - data->start_time;
	return (current_time);
}

void	ft_sleep(int time)
{
	long	start_time;

	start_time = get_time();
	while (get_time() - start_time < time)
		usleep(300);
}
