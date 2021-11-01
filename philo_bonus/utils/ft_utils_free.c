/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:46:01 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/14 12:23:16 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_philo_list(t_philo **philo_list, int target)
{
	int		i;
	char	semaphore_name[255];
	int		philo_num;

	i = 0;
	while (i < target)
	{
		philo_num = philo_list[i]->philo_num;
		ft_get_sem_name("semaphore_philo_", semaphore_name, philo_num);
		sem_close(philo_list[i]->sem_check_behavior);
		sem_unlink(semaphore_name);
		ft_get_sem_name("semaphore_behavior_", semaphore_name, philo_num);
		sem_close(philo_list[i]->sem_check_eat);
		sem_unlink(semaphore_name);
		free(philo_list[i]);
		i++;
	}
	free(philo_list);
}

void	ft_free_opt(t_option *opt)
{
	sem_close(opt->sem_fork);
	sem_unlink("semaphore_fork");
	sem_close(opt->sem_check_write);
	sem_unlink("semaphore_write");
	sem_close(opt->sem_check_dead);
	sem_unlink("semaphore_dead");
	sem_close(opt->sem_check_write);
	sem_unlink("semaphore_dead_write");
	free(opt);
}

void	ft_free_total(t_total *total)
{
	ft_free_philo_list(total->philo_list, total->opt->number_of_philo);
	ft_free_opt(total->opt);
	free(total);
}
