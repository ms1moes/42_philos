/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:23:52 by msimoes-          #+#    #+#             */
/*   Updated: 2023/04/28 02:23:52 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void init_data(int ac, char **av)
{
    data()->dead = 0;
    data()->num_philo = ft_atoi(av[1]);
    data()->time_to_die = ft_atoi(av[2]);
    data()->time_to_eat = ft_atoi(av[3]);
    data()->time_to_sleep = ft_atoi(av[4]);
    if(ac == 6)
        data()->num_meals = ft_atoi(av[5]);
    else
        data()->num_meals = -1;
    data()->philo = malloc(sizeof(t_philo) * data()->num_philo);
    if(!data()->philo)
        return ;
    data()->fork = malloc(sizeof(t_fork) * data()->num_philo);
    if(!data()->philo)
        return ;
    pthread_mutex_init(&data()->mutex_dead, NULL);
    pthread_mutex_init(&data()->mutex_print, NULL);
}

void *init_simulation(void *arg)
{
    t_philo *philo;

    philo = arg;
    if(philo->id % 2 == 0)
        usleep(10000);
    while (!death_status() && philo->total_meals != data()->num_meals)
    {
        eating(philo);
        sleeping(philo, get_time());
        is_dead(philo);
    }
    return (NULL);
}

void init_philo(void)
{
    int i;

    i = -1;
    while (++i < data()->num_philo)
    {
        pthread_mutex_init(&data()->fork[i].mutex_fork, NULL);
        data()->fork[i].fork_status = 1;
    }
    i = -1;
    data()->start = get_time();
    while (++i < data()->num_philo)
    {
        data()->philo[i].id = i + 1;
        data()->philo[i].total_meals = 0;
        data()->philo[i].forks = 0;
        data()->philo[i].last_meal = data()->start;
        pthread_create(&data()->philo[i].thread_philo, NULL, \
        &init_simulation, &data()->philo[i]);
    }
    i = -1;
    while (++i < data()->num_philo)
        pthread_join(data()->philo[i].thread_philo, NULL);
}