/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:19:57 by adouib            #+#    #+#             */
/*   Updated: 2022/02/11 14:19:58 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	alloc(t_data *data)
{
	int	philos_count;

	philos_count = data->number_of_philosophers;
	data->philos = malloc(sizeof(t_philo) * philos_count);
	if (!data->philos)
		return (0);
	data->forks = malloc(sizeof(int) * philos_count);
	if (!data->forks)
		return (0);
	data->locks = malloc(sizeof(pthread_mutex_t) * philos_count);
	if (!data->locks)
		return (0);
	data->tid = malloc(sizeof(pthread_t) * philos_count);
	if (!data->tid)
		return (0);
	return (1);
}
