/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:48:33 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/15 10:51:19 by jimikim          ###   ########.fr       */
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
			sem_wait(philo_list[i++]->sem_check_eat);
		count++;
	}
	sem_wait(opt->sem_check_write);
	sem_wait(opt->sem_dead_write);
	printf("all philos must eat done \n");
	sem_post(opt->sem_check_write);
	sem_post(opt->sem_check_dead);
	return ((void *)0);
}

void	*ft_monitor_philo(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	while (1)
	{
		sem_wait(philo->sem_check_behavior);
		if (!philo->state_eat && ft_get_time() > philo->black_hole)
		{
			ft_print_msg("died", philo);
			sem_post(philo->sem_check_behavior);
			sem_post(philo->opt->sem_check_dead);
			return ((void *)0);
		}
		sem_post(philo->sem_check_behavior);
		usleep(100);
	}
	return ((void *)0);
}
