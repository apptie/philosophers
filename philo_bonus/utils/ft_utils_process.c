/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:21:59 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/15 12:20:31 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_process_monitor(t_total *total)
{
	pthread_t	thread_id;
	t_option	*opt;

	opt = total->opt;
	if (opt->must_eat > 0)
	{
		if (pthread_create(&thread_id, NULL,
				ft_monitor_eat_count, (void *)total))
			exit(1);
		pthread_detach(thread_id);
	}
	return (1);
}

int	ft_process_philo(t_philo *philo)
{
	pthread_t	thread_id;

	philo->last_eat = ft_get_time();
	philo->black_hole = philo->last_eat + philo->opt->time_to_die;
	if (pthread_create(&thread_id, NULL, ft_monitor_philo, (void *)philo))
		return (0);
	pthread_detach(thread_id);
	while (1)
	{
		ft_philo_get_fork(philo);
		ft_philo_eat(philo);
		ft_philo_set_fork(philo);
		ft_print_msg("is thinking", philo);
	}
	return (1);
}

void	ft_process_process_sub(t_total *total)
{
	t_option	*opt;
	t_philo		**philo_list;
	int			i;

	opt = total->opt;
	philo_list = total->philo_list;
	i = -1;
	while (++i < opt->number_of_philo)
	{
		if (i % 2 == 0)
			continue ;
		philo_list[i]->pid = fork();
		if (philo_list[i]->pid < 0)
			exit(1);
		else if (philo_list[i]->pid == 0)
		{
			if (ft_process_philo(philo_list[i]) == 0)
				exit(1);
			exit(0);
		}
		usleep(1);
	}
}

void	ft_process_process(t_total *total)
{
	t_option	*opt;
	t_philo		**philo_list;
	int			i;

	opt = total->opt;
	philo_list = total->philo_list;
	opt->start_time = ft_get_time();
	i = -1;
	while (++i < opt->number_of_philo)
	{
		if (i % 2 != 0)
			continue ;
		philo_list[i]->pid = fork();
		if (philo_list[i]->pid < 0)
			exit(1);
		else if (philo_list[i]->pid == 0)
		{
			if (ft_process_philo(philo_list[i]) == 0)
				exit(1);
			exit(0);
		}
		usleep(1);
	}
	ft_process_process_sub(total);
}
