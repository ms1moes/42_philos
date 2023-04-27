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

typedef struct s_time
{
	unsigned long	start_time;

}t_time;

typedef struct s_dead
{
	int 			is_dead;
	pthread_mutex_t dead_mutex;

}t_dead;

typedef struct s_philo
{
	int 			id;
	int 			total_meals;
	unsigned long 	last_meal;
	pthread_t		philo;
	t_input			input;
	t_fork			*forks;
	t_time			*time;
	t_dead			*dead;

}t_philo;

int		ft_atoi(const char *str);
t_input *input(void);

# endif