/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 00:09:34 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/15 12:18:15 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_option	*opt;
	t_philo		**philo_list;
	t_total		*total;

	if (ft_check_opt(argc, argv) == 0)
		return (0);
	opt = ft_init_opt(argv);
	if (!opt)
		return (0);
	philo_list = ft_init_philo_list(opt);
	if (!philo_list)
		return (0);
	total = ft_init_total(opt, philo_list);
	if (!total)
		return (0);
	if (ft_start_thread(total) == 0)
	{
		ft_free_total(total);
		ft_putstr_fd("ft_start_thread error.\n", 2);
		return (0);
	}
	pthread_mutex_lock(&opt->mutex_check_dead);
	pthread_mutex_unlock(&opt->mutex_check_dead);
	return (0);
}
