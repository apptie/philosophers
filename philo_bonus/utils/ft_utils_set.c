/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:34:57 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/13 20:08:30 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_set_opt_sem(t_option *opt)
{
	sem_unlink("semaphore_fork");
	sem_unlink("semaphore_write");
	sem_unlink("semaphore_dead");
	sem_unlink("semaphore_dead_write");
	opt->sem_fork = ft_sem_open("semaphore_fork", opt->number_of_philo);
	opt->sem_check_dead = ft_sem_open("semaphore_dead", 0);
	opt->sem_check_write = ft_sem_open("semaphore_write", 1);
	opt->sem_dead_write = ft_sem_open("semaphore_dead_write", 1);
	if (opt->sem_fork == SEM_FAILED)
		return (0);
	if (opt->sem_check_dead == SEM_FAILED)
		return (0);
	if (opt->sem_check_write == SEM_FAILED)
		return (0);
	if (opt->sem_dead_write == SEM_FAILED)
		return (0);
	return (1);
}

int	ft_set_philo_sem(t_philo *philo)
{
	char	semaphore_name[255];

	ft_get_sem_name("semaphore_philo_", semaphore_name, philo->philo_num);
	sem_unlink(semaphore_name);
	philo->sem_check_behavior = ft_sem_open(semaphore_name, 1);
	if (philo->sem_check_behavior == SEM_FAILED)
		return (0);
	ft_get_sem_name("semaphore_behavior_", semaphore_name, philo->philo_num);
	sem_unlink(semaphore_name);
	philo->sem_check_eat = ft_sem_open(semaphore_name, 0);
	if (philo->sem_check_eat == SEM_FAILED)
		return (0);
	return (1);
}
