/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:59:50 by bvernimm          #+#    #+#             */
/*   Updated: 2022/06/13 10:25:24 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (1);
	while (argv[i])
	{
		if (ft_is_valid_digit(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_valid_digit(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '0')
		return (1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	if (ft_atoi(str) <= 0)
		return (1);
	return (0);
}
