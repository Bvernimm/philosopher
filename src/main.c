/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:53:04 by bvernimm          #+#    #+#             */
/*   Updated: 2022/06/02 15:15:08 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait(int64_t time)
{
	time = time + ft_time(1);
	while (1)
	{
		usleep(50);
		if (time <= ft_time(1))
			break ;
	}
}

int64_t	ft_time(int indicator)
{
	static int64_t	start_time;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if (indicator == 0)
		start_time = (current_time.tv_usec / 1000)
			+ (current_time.tv_sec * 1000);
	if (indicator == 1)
		return ((current_time.tv_usec / 1000) + (current_time.tv_sec * 1000)
			- start_time);
	return (0);
}

void	ft_free(t_init **arg)
{
	int	i;

	i = 0;
	if (!arg || !(*arg))
		return ;
	if ((*arg)->philo)
	{
		while (i < (*arg)->nb_philo)
		{
			pthread_mutex_destroy(&(*arg)->philo[i].fork);
			i++;
		}
		free((*arg)->philo);
	}
	pthread_mutex_destroy(&(*arg)->start);
	pthread_mutex_destroy(&(*arg)->lock);
	free((*arg));
}

int	main(int argc, char **argv)
{
	t_init	*arg;

	if (check_arg(argc, argv) == 1)
	{
		printf ("Invalid argument\n");
		return (1);
	}
	if (init(&arg, argv, argc) != 0)
	{
		ft_free(&arg);
		return (1);
	}
	if (start(&arg) != 0)
	{
		ft_free(&arg);
		return (1);
	}
	ft_free(&arg);
	return (0);
}
