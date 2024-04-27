/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:08:38 by rosman            #+#    #+#             */
/*   Updated: 2024/04/26 20:33:51 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 1- eating
 2- sleeping
 3- thinking
*/

void	*routine(void *philoso)
{
	t_philo	*philo;

	philo = (t_philo *)philoso;
	if (philo->data->philo_no == 1)
		one_philo(philo);
	pthread_mutex_lock(&philo->data->ending);
	while (philo->data->finish == 0)
	{
		pthread_mutex_unlock(&philo->data->ending);
		eating(philo);
		sleeping(philo);
		thinking(philo);
		pthread_mutex_lock(&philo->data->ending);
	}
	pthread_mutex_unlock(&philo->data->ending);
	return (NULL);
}
