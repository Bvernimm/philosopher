/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:52:17 by bvernimm          #+#    #+#             */
/*   Updated: 2022/06/02 10:25:10 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <inttypes.h>
# include <stdatomic.h>

typedef struct s_philosophe
{
	pthread_t		pid;
	atomic_int		philo_nb;
	atomic_int		voisin;
	atomic_int		time_eaten;
	atomic_int		time_stop;
	struct s_init	**arg;
	pthread_mutex_t	fork;
}					t_philosophe;

typedef struct s_init
{
	atomic_int		nb_philo;
	atomic_int		time_to_die;
	atomic_int		time_to_eat;
	atomic_int		time_to_sleep;
	atomic_int		nb_to_eat;
	atomic_int		philo_full;
	atomic_int		stop;
	t_philosophe	*philo;
	pthread_mutex_t	lock;
	pthread_mutex_t	start;
}					t_init;

/*main*/
void	ft_wait(int64_t time);
int64_t	ft_time(int indicator);
void	ft_free(t_init **arg);

/*check_arg*/
int		check_arg(int argc, char **argv);
int		ft_is_valid_digit(char *str);

/*init*/
int		init(t_init **arg, char **argv, int argc);
int		init_philo(t_init **arg);

/*utils*/
int		ft_atoi(char *str);

/*start*/
void	*routine(void *philosophe);
void	monitoring(t_init **arg);
int		start(t_init **arg);

/*act*/
void	speak(t_init **arg, int philo, char *str);
void	eat(t_init **arg, t_philosophe *philo);
void	sleeping(t_init **arg, t_philosophe *philo);

#endif