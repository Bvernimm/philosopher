/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:16:19 by bvernimm          #+#    #+#             */
/*   Updated: 2022/06/13 10:38:57 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philosophe)
{
	t_philosophe	*philo;
	t_init			**arg;

	philo = (t_philosophe *)philosophe;
	arg = philo->arg;
	pthread_mutex_lock(&(*arg)->start);
	pthread_mutex_unlock(&(*arg)->start);
	philo->time_stop = ft_time(1) + (*arg)->time_to_die;
	if (philo->philo_nb % 2)
		ft_wait((*arg)->time_to_eat / 2);
	while ((*arg)->stop)
	{
		eat(arg, philo);
		if (philo->time_eaten == (*arg)->nb_to_eat)
			(*arg)->philo_full++;
		sleeping(arg, philo);
		speak(arg, philo->philo_nb, "is thinking");
	}
	return (0);
}

void	monitoring(t_init **arg)
{
	int				i;
	t_philosophe	*philo;

	i = 0;
	philo = (*arg)->philo;
	while (1)
	{
		if (i >= (*arg)->nb_philo)
			i = 0;
		if (philo[i].time_stop < ft_time(1)
			|| (*arg)->philo_full == (*arg)->nb_philo)
		{
			pthread_mutex_lock(&(*arg)->lock);
			(*arg)->stop = 0;
			if ((*arg)->philo_full != (*arg)->nb_philo)
				printf("%d %d %s\n", ft_time(1), philo[i].philo_nb, "died");
			pthread_mutex_unlock(&(*arg)->lock);
			if ((*arg)->nb_philo == 1)
				pthread_mutex_unlock(&philo[0].fork);
			return ;
		}
		i++;
	}
}

int	start(t_init **arg)
{
	int				i;
	t_philosophe	*philo;

	i = 0;
	philo = (*arg)->philo;
	pthread_mutex_lock(&(*arg)->start);
	while (i < (*arg)->nb_philo)
	{
		if (pthread_create(&philo[i].pid, NULL, &routine, &philo[i]) != 0)
			return (1);
		i++;
	}
	ft_time(0);
	pthread_mutex_unlock(&(*arg)->start);
	ft_wait((*arg)->time_to_die);
	monitoring(arg);
	i = 0;
	while (i < (*arg)->nb_philo)
	{
		if (pthread_join(philo[i].pid, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
