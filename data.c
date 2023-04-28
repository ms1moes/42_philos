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

t_input init_input(int ac, char **av)
{
    t_input input;

    input.num_philo = ft_atoi(av[1]);
    input.time_to_die = ft_atoi(av[2]);
    input.time_to_eat = ft_atoi(av[3]);
    input.time_to_sleep = ft_atoi(av[4]);
    if(ac == 6)
        input.num_meals = ft_atoi(av[5]);
    else
        input.num_meals = -1;
    return (input);
}

t_fork *init_forks(t_input *input)
{
    t_fork *fork;
    int i;

    fork = malloc(sizeof(t_fork) * input.num_philo);
    if(!fork)
        return (NULL);
    i = -1;
    while(++i < input.num_philo)
    {
        fork[i].fork_status = 1;
        pthread_mutex_init(&fork[i].fork_mutex, NULL);
    }
    return (fork);
}

t_death init_death(void)
{
    static t_death death;

    pthread_mutex_init(&death.death_mutex, NULL);
    return (&death);
}