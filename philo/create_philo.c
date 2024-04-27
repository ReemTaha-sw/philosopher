/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:25:43 by rosman            #+#    #+#             */
/*   Updated: 2024/04/27 22:04:46 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->last_meal_locker);
	if ((get_time() - philo->last_meal) >= philo->data->die_t)
	{
		pthread_mutex_unlock(&philo->data->last_meal_locker);
		pthread_mutex_lock(&philo->data->ending);
		philo->data->finish = 1;
		pthread_mutex_unlock(&philo->data->ending);
		if (philo->data->philo_no != 1)
			printing(philo, "\033[1;31mdied\033[0m", time_calc(philo), 1);
	}
	else
		pthread_mutex_unlock(&philo->data->last_meal_locker);
}

void	cheack_meal_no(t_data *data)
{
	pthread_mutex_lock(&data->meals_no_locker);
	if (data->meal_count >= (data->philo_no * data->num_to_eat))
	{
		pthread_mutex_unlock(&data->meals_no_locker);
		pthread_mutex_lock(&data->ending);
		data->finish = 1;
		pthread_mutex_unlock(&data->ending);
		return ;
	}
	pthread_mutex_unlock(&data->meals_no_locker);
}

void	create_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_no)
	{
		if (pthread_create(&data->t_philos[i].thread, NULL,
				&routine, &(data->t_philos[i])) != 0)
			return ;
	}
	i = -1;
	pthread_mutex_lock(&data->ending);
	while (data->finish == 0)
	{
		pthread_mutex_unlock(&data->ending);
		is_dead(&data->t_philos[++i % data->philo_no]);
		if (data->num_to_eat > 0)
			cheack_meal_no(data);
		usleep(500);
		pthread_mutex_lock(&data->ending);
	}
	pthread_mutex_unlock(&data->ending);
}
