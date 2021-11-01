/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:42:46 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/15 11:18:33 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitor_eat_count(void *total_void)
{
	t_option	*opt;
	t_philo		**philo_list;
	int			i;
	int			count;

	opt = ((t_total *)total_void)->opt;
	philo_list = ((t_total *)total_void)->philo_list;
	count = 0;
	while (count < opt->must_eat)
	{
		i = 0;
		while (i < opt->number_of_philo)
			pthread_mutex_lock(&philo_list[i++]->mutex_check_eat);
		count++;
	}
	pthread_mutex_lock(&opt->mutex_check_write);
	pthread_mutex_lock(&opt->mutex_dead_write);
	printf("all philos must eat done \n");
	pthread_mutex_unlock(&opt->mutex_check_write);
	pthread_mutex_unlock(&opt->mutex_check_dead);
	return ((void *)0);
}

void	*ft_monitor_philo(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex_check_behavior);
		if (!philo->state_eat && ft_get_time() > philo->black_hole)
		{
			pthread_mutex_unlock(&philo->mutex_check_behavior);
			ft_print_msg("died", philo);
			pthread_mutex_unlock(&philo->opt->mutex_check_dead);
			return ((void *)0);
		}
		pthread_mutex_unlock(&philo->mutex_check_behavior);
		usleep(100);
	}
}

void	*ft_process_philo(void *philo_void)
{
	t_philo		*philo;
	pthread_t	monitor_id;

	philo = (t_philo *)philo_void;
	philo->last_eat = ft_get_time();
	philo->black_hole = philo->last_eat + philo->opt->time_to_die;
	if (pthread_create(&monitor_id, NULL, ft_monitor_philo, philo_void))
		return ((void *)1);
	pthread_detach(monitor_id);
	while (1)
	{
		ft_philo_get_fork(philo);
		ft_philo_eat(philo);
		ft_philo_set_fork(philo);
		ft_print_msg("is thinking", philo);
	}
	return ((void *)0);
}
