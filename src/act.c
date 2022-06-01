/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:11:56 by bvernimm          #+#    #+#             */
/*   Updated: 2022/06/01 15:38:36 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	speak(pthread_mutex_t *lock, int philo, char *str, int stop)
{
	pthread_mutex_lock(lock);
	if (stop)
		printf("%lld %d %s\n", ft_time(1), philo, str);
	pthread_mutex_unlock(lock);
}

void	eat(t_init **arg, t_philosophe *philo)
{
	pthread_mutex_lock(&philo->fork);
	speak(&(*arg)->lock, philo->philo_nb, "has taken a fork", (*arg)->stop);
	pthread_mutex_lock(&(*arg)->philo[philo->voisin].fork);
	speak(&(*arg)->lock, philo->philo_nb, "has taken a fork", (*arg)->stop);
	philo->time_stop = ft_time(1) + ((*arg)->time_to_die);
	speak(&(*arg)->lock, philo->philo_nb, "is eating", (*arg)->stop);
	ft_wait((*arg)->time_to_eat);
	philo->time_eaten++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&(*arg)->philo[philo->voisin].fork);
}

void	sleeping(t_init **arg, t_philosophe *philo)
{
	speak(&(*arg)->lock, philo->philo_nb, "is sleeping", (*arg)->stop);
	ft_wait((*arg)->time_to_sleep);
}
