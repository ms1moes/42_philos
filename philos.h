/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:33:14 by msimoes-          #+#    #+#             */
/*   Updated: 2023/04/26 17:33:14 by msimoes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_input
{
	int num_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_meals;

}t_input;

typedef struct s_fork
{
	int 			fork_status;

	pthread_mutex_t fork_mutex;

}t_fork;

typedef struct s_death
{
	int 			is_dead;

	pthread_mutex_t death_mutex;

}t_death;

typedef struct s_philo
{
	int 			id;
	int 			total_meals;
	unsigned long 	last_meal;
	unsigned long	start_time;

	t_input			input;
	t_fork			*fork;
	t_time			*time;
	t_death			*death;

	pthread_t		philo;

}t_philo;

int		ft_atoi(const char *str);

t_input init_input(int ac, char **av);
t_fork *init_forks(t_input *input);
t_death init_death(void);

# endif