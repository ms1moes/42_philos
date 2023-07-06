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

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

int main(int ac, char **av)
{
    if(ac != 5 && ac != 6)
    {
        init_data(ac, av);
        if(data().time_to_die > 0 && data()->time_to_eat > 0 && \
        data()->time_to_sleep > 0 && data()->num_philo > 0)
        init_philo();
        end_prog();
    }
}