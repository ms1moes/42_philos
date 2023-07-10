/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:38:33 by msimoes-          #+#    #+#             */
/*   Updated: 2023/07/10 01:48:41 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	ft_atoi(const char *str)
{
	long	n;

	n = 0;
	while (*str >= '0' && *str <= '9')
		n = (n * 10) + (*str++ - '0');
	return (n);
}

long int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void end_prog(void)
{
	int i;

	i = -1;
	while (++i < data()->num_philo)
		pthread_mutex_destroy(&data()->fork[i].mutex_fork);
	pthread_mutex_destroy(&data()->mutex_dead);
	pthread_mutex_destroy(&data()->mutex_print);
	if(data()->fork)
		free(data()->fork);
	if(data()->philo)
		free(data()->philo);
	exit(0);
	
}

void	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&data()->mutex_print);
	if (!death_status())
		printf("%ld %d %s\n", (get_time() - data()->start), philo->id, msg);
	pthread_mutex_unlock(&data()->mutex_print);
}