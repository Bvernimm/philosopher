/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:02:56 by bvernimm          #+#    #+#             */
/*   Updated: 2022/06/01 15:38:43 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_init **arg, char **argv, int argc)
{
	(*arg) = malloc (sizeof(t_init));
	if (!(*arg))
		return (1);
	(*arg)->nb_philo = ft_atoi(argv[1]);
	(*arg)->time_to_die = ft_atoi(argv[2]);
	(*arg)->time_to_eat = ft_atoi(argv[3]);
	(*arg)->time_to_sleep = ft_atoi(argv[4]);
	(*arg)->nb_to_eat = -1;
	if (argc == 6)
		(*arg)->nb_to_eat = ft_atoi(argv[5]);
	(*arg)->philo_full = 0;
	(*arg)->stop = 1;
	(*arg)->philo = malloc(sizeof(t_philosophe) * (*arg)->nb_philo);
	if ((*arg)->philo == NULL)
		return (1);
	if (init_philo(arg) != 0)
		return (1);
	if (pthread_mutex_init(&(*arg)->lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(*arg)->start, NULL) != 0)
		return (1);
	return (0);
}

int	init_philo(t_init **arg)
{
	int				i;

	i = 0;
	while (i < (*arg)->nb_philo)
	{
		(*arg)->philo[i].philo_nb = i + 1;
		(*arg)->philo[i].voisin = i + 1;
		if (i + 1 == (*arg)->nb_philo)
			(*arg)->philo[i].voisin = 0;
		(*arg)->philo[i].time_eaten = 0;
		(*arg)->philo[i].arg = arg;
		if (pthread_mutex_init(&(*arg)->philo[i].fork, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
