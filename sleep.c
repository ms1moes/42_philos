/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:42:06 by msimoes-          #+#    #+#             */
/*   Updated: 2023/07/13 18:42:06 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void    sleeping(t_philo *philo, long int start)
{
    if (philo->total_meals != data()->num_meals)
		print_msg(philo, "is sleeping");
	while (!death_status() && ((get_time() - start) < data()->time_to_sleep))
	{
		is_dead(philo);
		usleep(1);
	}
	is_dead(philo);
	if (philo->total_meals != data()->num_meals)
		print_msg(philo, "is thinking");
}