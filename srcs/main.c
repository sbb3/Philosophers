/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:20:07 by adouib            #+#    #+#             */
/*   Updated: 2022/02/11 18:54:25 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	main(int ac, char const *av[])
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (printf("Incorrect arguments\n"));
	if (parser(av, &data))
		return (printf("Incorrect arguments\n"));
	alloc(&data);
	init(&data);
	if (thread_handler(&data))
		return (1);
	watcher(&data);
	clear(&data);
	return (0);
}
