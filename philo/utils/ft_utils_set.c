/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 22:24:09 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/13 17:55:26 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_set_opt_mutex_sub(t_option *opt)
{
	int	i;

	i = 0;
	while (i < opt->number_of_philo)
	{
		if (pthread_mutex_init(&opt->mutex_fork[i], NULL) != 0)
		{
			free(opt->mutex_fork);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_set_opt_mutex(t_option *opt)
{
	opt->mutex_fork = malloc(sizeof(pthread_mutex_t) * opt->number_of_philo);
	if (!opt->mutex_fork)
		return (0);
	if (ft_set_opt_mutex_sub(opt) == 0)
		return (0);
	if (pthread_mutex_init(&opt->mutex_check_dead, NULL) != 0)
	{
		free(opt->mutex_fork);
		return (0);
	}
	if (pthread_mutex_init(&opt->mutex_check_write, NULL) != 0)
	{
		free(opt->mutex_fork);
		return (0);
	}
	if (pthread_mutex_init(&opt->mutex_dead_write, NULL) != 0)
	{
		free(opt->mutex_fork);
		return (0);
	}
	pthread_mutex_lock(&opt->mutex_check_dead);
	return (1);
}

int	ft_set_philo_mutex(t_philo *philo)
{
	if (pthread_mutex_init(&philo->mutex_check_behavior, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&philo->mutex_check_eat, NULL) != 0)
		return (0);
	pthread_mutex_lock(&philo->mutex_check_eat);
	return (1);
}
