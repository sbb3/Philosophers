/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:20:34 by adouib            #+#    #+#             */
/*   Updated: 2022/02/11 17:02:47 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r'\
	|| c == '\f' || c == '\v')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *s)
{
	long			num;
	size_t			i;
	int				k;
	int				sign;

	sign = 1;
	num = 0;
	i = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			return (-1);
	k = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10) + (s[i++] - '0');
		k = 1;
	}
	if (num > INT_MAX || k == 0)
		return (-1);
	return (sign * num);
}

int	parser(const char *av[], t_data *data)
{
	data->notepme_argument = 0;
	data->number_of_philosophers = ft_atoi(av[1]);
	if (data->number_of_philosophers == -1)
		return (1);
	data->time_to_die = ft_atoi(av[2]);
	if (data->time_to_die == -1)
		return (1);
	data->time_to_eat = ft_atoi(av[3]);
	if (data->time_to_eat == -1)
		return (1);
	data->time_to_sleep = ft_atoi(av[4]);
	if (data->time_to_sleep == -1)
		return (1);
	if (av[5])
	{
		data->notepme_argument = 1;
		data->philos_max_eat = ft_atoi(av[5]);
		if (data->philos_max_eat == -1)
			return (1);
	}
	return (0);
}
