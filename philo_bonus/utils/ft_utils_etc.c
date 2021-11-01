/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_etc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:50:42 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/15 10:09:31 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	ft_get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void	ft_usleep(unsigned long long delay)
{
	unsigned long long	target;

	target = ft_get_time() + delay;
	while (target > ft_get_time())
	{
	}
}

void	ft_print_msg(char *s, t_philo *philo)
{
	t_option	*opt;

	opt = philo->opt;
	sem_wait(philo->opt->sem_check_write);
	sem_wait(philo->opt->sem_dead_write);
	printf("%lld ", ft_get_time() - opt->start_time);
	printf("%d ", philo->philo_num);
	printf("%s\n", s);
	if (ft_strncmp(s, "died", 4) != 0)
		sem_post(philo->opt->sem_dead_write);
	sem_post(philo->opt->sem_check_write);
}
