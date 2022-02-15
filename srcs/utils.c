/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:30:58 by adouib            #+#    #+#             */
/*   Updated: 2022/02/11 18:44:44 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	display_status(t_philo *philo, int philo_num, char *s)
{
	pthread_mutex_lock(&philo->data->display_lock);
	if (philo->data->simulation_begin == START)
		printf(s, timestamp_im_ms(philo), philo_num);
	pthread_mutex_unlock(&philo->data->display_lock);
}

int	odd_philos(int id)
{
	if (id % 2)
		return (1);
	return (0);
}

/*destroying the mutexes and free everything*/
void	clear(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->locks[i]);
	pthread_mutex_destroy(&data->eat_lock);
	pthread_mutex_destroy(&data->display_lock);
	if (data->philos)
		free(data->philos);
	if (data->locks)
		free(data->locks);
	if (data->tid)
		free(data->tid);
}
