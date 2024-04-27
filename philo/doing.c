/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:18:21 by rosman            #+#    #+#             */
/*   Updated: 2024/04/26 19:54:38 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 1- checking the status
 2- printing "is doing"
 3- spend the time to do
*/

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->ending);
	if (philo->data->finish == 0)
	{
		pthread_mutex_unlock(&philo->data->ending);
		printing(philo, "is sleeping", time_calc(philo), 0);
		spend_time(philo, philo->data->sleep_t);
		return ;
	}
	pthread_mutex_unlock(&philo->data->ending);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->ending);
	if (philo->data->finish == 0)
	{
		pthread_mutex_unlock(&philo->data->ending);
		printing(philo, "is thinking", time_calc(philo), 0);
		return ;
	}
	pthread_mutex_unlock(&philo->data->ending);
}

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_locker[philo->r_fork]);
	printing(philo, "\e[0;32mhas taken a fork\033[0m", time_calc(philo), 0);
	philo->data->fork[philo->r_fork] = philo->id;
	spend_time(philo, philo->data->die_t);
	printing(philo, "\033[1;31mdied\033[0m", time_calc(philo), 1);
	pthread_mutex_unlock(&philo->data->fork_locker[philo->r_fork]);
	pthread_mutex_lock(&philo->data->ending);
	philo->data->finish = 1;
	pthread_mutex_unlock(&philo->data->ending);
}
