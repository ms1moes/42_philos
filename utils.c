/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:38:33 by msimoes-          #+#    #+#             */
/*   Updated: 2023/04/28 02:21:01 by msimoes-         ###   ########.fr       */
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