/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:10:35 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/15 12:16:58 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start_thread_even(t_total *total)
{
	int			i;
	t_philo		**philo_list;
	t_option	*opt;

	i = -1;
	philo_list = total->philo_list;
	opt = total->opt;
	while (++i < opt->number_of_philo)
	{
		if (i % 2 != 0)
			continue ;
		if (pthread_create(&philo_list[i]->thread_id, NULL,
				ft_process_philo, (void *)philo_list[i]) != 0)
			return (0);
		pthread_detach(philo_list[i]->thread_id);
		usleep(1);
	}
	return (1);
}

int	ft_start_thread_odd(t_total *total)
{
	int			i;
	t_philo		**philo_list;
	t_option	*opt;

	i = -1;
	philo_list = total->philo_list;
	opt = total->opt;
	while (++i < opt->number_of_philo)
	{
		if (i % 2 == 0)
			continue ;
		if (pthread_create(&philo_list[i]->thread_id, NULL,
				ft_process_philo, (void *)philo_list[i]) != 0)
			return (0);
		pthread_detach(philo_list[i]->thread_id);
		usleep(1);
	}
	return (1);
}

int	ft_start_thread(t_total *total)
{
	t_philo		**philo_list;
	t_option	*opt;

	philo_list = total->philo_list;
	opt = total->opt;
	opt->start_time = ft_get_time();
	if (opt->must_eat > 0)
	{
		if (pthread_create(&opt->eat_thread, NULL,
				ft_monitor_eat_count, (void *)total) != 0)
			return (0);
		pthread_detach(opt->eat_thread);
	}
	if (ft_start_thread_even(total) == 0)
		return (0);
	if (ft_start_thread_odd(total) == 0)
		return (0);
	return (1);
}
