/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:45:52 by rosman            #+#    #+#             */
/*   Updated: 2024/04/04 18:10:39 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_int(const char *str)
{
	long long	i;
	long long	count;

	i = 0;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		++i;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		count++;
		i++;
	}
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		++i;
	if (str[i] != '\0' || count > 18)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;
	unsigned long long	max;

	result = 0;
	sign = 1;
	max = LONG_MAX;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > max && sign == 1)
			return (-1);
		if (result > max && sign == -1)
			return (0);
		str++;
	}
	return (result * sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*allocated_memory;
	size_t	total_size;

	if (size == '\0' && count > UINT32_MAX / size)
		return (NULL);
	total_size = count * size;
	allocated_memory = malloc(total_size);
	if (allocated_memory != NULL )
		memset(allocated_memory, 0, total_size);
	else
		return (NULL);
	return (allocated_memory);
}
