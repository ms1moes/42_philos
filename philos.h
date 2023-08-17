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

typedef struct s_fork
{
	int				fork_status;
	pthread_mutex_t	mutex_fork;

}t_fork;

typedef struct s_philo
{
	int				id;
	int				total_meals;
	int				forks;
	long int		last_meal;
	pthread_t		thread_philo;

}t_philo;

typedef struct s_data
{
	int					dead;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_meals;
	int					num_philo;
	long int			start;
	pthread_mutex_t		mutex_dead;
	pthread_mutex_t		mutex_print;
	t_philo				*philo;
	t_fork				*fork;

}t_data;

t_data		*data(void);
long int	get_time(void);
void		print_msg(t_philo *philo, char *msg);
int			ft_atoi(const char *str);
int			death_status(void);
int			is_dead(t_philo *philo);
void		init_data(int ac, char **av);
void		sleeping(t_philo *philo, long int start);
void		eating(t_philo *philo);
void		init_philo(void);
void		end_prog(void);

#endif