/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 21:55:07 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/15 10:53:25 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_get_fork(t_philo *philo)
{
	sem_wait(philo->opt->sem_fork);
	ft_print_msg("has taken a fork", philo);
	sem_wait(philo->opt->sem_fork);
	ft_print_msg("has taken a fork", philo);
}

void	ft_philo_set_fork(t_philo *philo)
{
	ft_print_msg("is sleeping", philo);
	sem_post(philo->opt->sem_fork);
	sem_post(philo->opt->sem_fork);
	ft_usleep(philo->opt->time_to_sleep);
}

void	ft_philo_eat(t_philo *philo)
{
	sem_wait(philo->sem_check_behavior);
	philo->state_eat = 1;
	philo->last_eat = ft_get_time();
	philo->black_hole = philo->last_eat + philo->opt->time_to_die;
	ft_print_msg("is eating", philo);
	ft_usleep(philo->opt->time_to_eat);
	philo->eat_count++;
	philo->state_eat = 0;
	sem_post(philo->sem_check_behavior);
	sem_post(philo->sem_check_eat);
}
