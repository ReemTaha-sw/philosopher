/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:40:33 by rosman            #+#    #+#             */
/*   Updated: 2024/04/26 18:00:00 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checking_ar(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!is_int(av[i]))
			return (1);
		i++;
	}
	return (0);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	time_calc(t_philo *philo)
{
	return (get_time() - philo->data->start_t);
}

void	destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_no)
		if (pthread_join(data->t_philos[i].thread, NULL) != 0)
			return ;
	i = -1;
	while (++i < data->philo_no)
		pthread_mutex_destroy(&data->fork_locker[i]);
	pthread_mutex_destroy(&data->meals_no_locker);
	pthread_mutex_destroy(&data->last_meal_locker);
	pthread_mutex_destroy(&data->ending);
	free(data);
}

void	printing(t_philo *philo, char *text, long long time, int i)
{
	pthread_mutex_lock(&philo->data->ending);
	if (philo->data->finish == 0 || i)
		printf("%lld %d %s\n", time, philo->id, text);
	pthread_mutex_unlock(&philo->data->ending);
}
