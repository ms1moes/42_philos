/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 03:18:36 by msimoes-          #+#    #+#             */
/*   Updated: 2023/04/27 03:18:36 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void get_input(char **av)
{
    input()->num_philo = ft_atoi(av[1]);
    input()->time_to_die = ft_atoi(av[2]);
    input()->time_to_eat = ft_atoi(av[3]);
    input()->time_to_sleep = ft_atoi(av[4]);
    if(av[5])
        input()->num_meals = ft_atoi(av[5]);
    else
        input()->num_meals = -1;
}

int main(int ac, char **av)
{
    (void)av;
    if(ac != 5 && ac != 6)
        return 1;
}