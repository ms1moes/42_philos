/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:01:04 by msimoes-          #+#    #+#             */
/*   Updated: 2023/07/13 18:01:04 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static void	take_fork(t_philo *philo, int slot)
{
	pthread_mutex_lock(&data()->fork[slot].mutex_fork);
	if (data()->fork[slot].fork_status)
	{
		data()->fork[slot].fork_status = 0;
		philo->forks++;
		if (philo->total_meals != data()->num_meals)
			print_msg(philo, "has taken a fork");
	}
	pthread_mutex_unlock(&data()->fork[slot].mutex_fork);
}

static void	return_fork(t_philo *philo, int fork)
{
	pthread_mutex_lock(&data()->fork[fork].mutex_fork);
	data()->fork[fork].fork_status = 1;
	pthread_mutex_unlock(&data()->fork[fork].mutex_fork);
	philo->forks = 0;
}

void	eating(t_philo *philo)
{
	int	first;
	int	second;

	first = philo->id - 1;
	second = (philo->id != data()->num_philo) * philo->id;
	while (!death_status() && philo->forks != 2)
	{
		take_fork(philo, first);
		is_dead(philo);
		take_fork(philo, second);
		is_dead(philo);
	}
	philo->last_meal = get_time();
	if ((philo->total_meals <= data()->num_meals || data()->num_meals == -1))
		print_msg(philo, "is eating");
	while (!death_status() && ((get_time() - philo->last_meal) \
	< data()->time_to_eat))
	{
		is_dead(philo);
		usleep(1);
	}
	return_fork(philo, first);
	return_fork(philo, second);
	if (data()->num_meals != -1)
		philo->total_meals++;
}
