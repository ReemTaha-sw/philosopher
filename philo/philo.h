/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:13:00 by rosman            #+#    #+#             */
/*   Updated: 2024/04/26 19:42:43 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

# define MAX_PHILO 200

typedef struct s_philo
{
	int				id;
	int				r_fork;
	int				l_fork;
	long long		last_meal;
	pthread_t		thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				philo_no;
	long long		eat_t;
	long long		die_t;
	long long		sleep_t;
	long long		start_t;
	int				meal_count;
	int				num_to_eat;
	t_philo			t_philos[MAX_PHILO];
	pthread_mutex_t	fork_locker[MAX_PHILO];
	pthread_mutex_t	meals_no_locker;
	pthread_mutex_t	last_meal_locker;
	pthread_mutex_t	ending;
	int				finish;
	int				fork[MAX_PHILO];
}	t_data;

int			is_int(const char *str);
int			checking_ar(char **av);
int			ft_atoi(const char *str);
int			data_init(t_data *data, int ac, char **av);
void		*ft_calloc(size_t count, size_t size);
void		create_philo(t_data *data);
void		*routine(void *philo);
void		destroy(t_data *data);
void		eating(t_philo *philo);
void		printing(t_philo *philo, char *text, long long time, int i);
void		spend_time(t_philo *philo, long long time);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		one_philo(t_philo *philo);
long long	time_calc(t_philo *philo);
long long	get_time(void);

#endif