/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:14:59 by rosman            #+#    #+#             */
/*   Updated: 2024/04/26 19:41:02 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_zeros(t_data *data, int ac)
{
	if (data->philo_no <= 0 || data->die_t < 60 || data->eat_t < 60
		|| data->sleep_t < 60 || (ac == 6 && data->num_to_eat <= 0))
	{
		printf("Invalid Args!\n");
		free(data);
		return (1);
	}
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = -1;
	if (data->philo_no < 201)
	{
		while (++i < data->philo_no)
		{
			data->t_philos[i].data = data;
			data->t_philos[i].id = i + 1;
			data->t_philos[i].last_meal = get_time();
			data->fork[i] = 0;
			pthread_mutex_init(&data->fork_locker[i], NULL);
			data->t_philos[i].r_fork = i;
			if (data->philo_no > 1)
				data->t_philos[i].l_fork = (i + 1) % data->philo_no;
		}
		return (0);
	}
	else
		return (printf("Max number of philo is 200.\n"));
}

int	data_init(t_data *data, int ac, char **av)
{
	data->philo_no = ft_atoi(av[1]);
	data->die_t = ft_atoi(av[2]);
	data->eat_t = ft_atoi(av[3]);
	data->sleep_t = ft_atoi(av[4]);
	data->start_t = get_time();
	data->finish = 0;
	data->meal_count = 0;
	data->num_to_eat = 0;
	if (ac == 6)
		data->num_to_eat = ft_atoi(av[5]);
	pthread_mutex_init(&data->meals_no_locker, NULL);
	pthread_mutex_init(&data->last_meal_locker, NULL);
	pthread_mutex_init(&data->ending, NULL);
	if (init_philo(data))
		return (1);
	if (is_zeros(data, ac))
		return (1);
	return (0);
}
