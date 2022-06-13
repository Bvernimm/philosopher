/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:11:56 by bvernimm          #+#    #+#             */
/*   Updated: 2022/06/13 10:34:22 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	speak(t_init **arg, int philo, char *str)
{
	pthread_mutex_lock(&(*arg)->lock);
	if ((*arg)->stop != 0)
		printf("%d %d %s\n", ft_time(1), philo, str);
	pthread_mutex_unlock(&(*arg)->lock);
}

void	eat(t_init **arg, t_philosophe *philo)
{
	pthread_mutex_lock(&philo->fork);
	speak(arg, philo->philo_nb, "has taken a fork");
	pthread_mutex_lock(&(*arg)->philo[philo->voisin].fork);
	speak(arg, philo->philo_nb, "has taken a fork");
	philo->time_stop = ft_time(1) + ((*arg)->time_to_die);
	speak(arg, philo->philo_nb, "is eating");
	ft_wait((*arg)->time_to_eat);
	philo->time_eaten++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&(*arg)->philo[philo->voisin].fork);
}

void	sleeping(t_init **arg, t_philosophe *philo)
{
	speak(arg, philo->philo_nb, "is sleeping");
	ft_wait((*arg)->time_to_sleep);
}
