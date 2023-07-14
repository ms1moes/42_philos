/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:21:34 by msimoes-          #+#    #+#             */
/*   Updated: 2023/07/10 01:21:34 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int death_status(void)
{
    int death;

    pthread_mutex_lock(&data()->mutex_dead);
    death = data()->dead;
    pthread_mutex_unlock(&data()->mutex_dead);
    return (death);
}

int is_dead(t_philo *philo)
{
    if (death_status())
        return (1);
    if ((get_time() - philo->last_meal) >= data()->time_to_die)
    {
        pthread_mutex_lock(&data()->mutex_dead);
        data()->dead++;
        if(data()->dead == 1)
            print_msg(philo, "died");
        pthread_mutex_unlock(&data()->mutex_dead);
        return (1);
    }
    return (0);
}