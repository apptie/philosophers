/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 01:07:08 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/14 22:00:26 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_get_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->opt->mutex_fork[philo->l_fork]);
	ft_print_msg("has taken a fork", philo);
	pthread_mutex_lock(&philo->opt->mutex_fork[philo->r_fork]);
	ft_print_msg("has taken a fork", philo);
}

void	ft_philo_set_fork(t_philo *philo)
{
	ft_print_msg("is sleeping", philo);
	pthread_mutex_unlock(&philo->opt->mutex_fork[philo->l_fork]);
	pthread_mutex_unlock(&philo->opt->mutex_fork[philo->r_fork]);
	ft_usleep(philo->opt->time_to_sleep);
}

void	ft_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_check_behavior);
	philo->state_eat = 1;
	ft_print_msg("is eating", philo);
	philo->last_eat = ft_get_time();
	philo->black_hole = philo->last_eat + philo->opt->time_to_die;
	ft_usleep(philo->opt->time_to_eat);
	philo->eat_count++;
	philo->state_eat = 0;
	pthread_mutex_unlock(&philo->mutex_check_behavior);
	pthread_mutex_unlock(&philo->mutex_check_eat);
}
