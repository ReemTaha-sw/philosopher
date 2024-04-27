/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:08:36 by rosman            #+#    #+#             */
/*   Updated: 2024/04/26 18:17:09 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
		return (printf("Args should be like: ./philo 5 800 200 200.\n"));
	if (checking_ar(av))
		return (printf("Invalid Args!\n"));
	data = ft_calloc(1, sizeof(t_data));
	if (data_init(data, ac, av))
		return (1);
	create_philo(data);
	destroy(data);
	return (0);
}
