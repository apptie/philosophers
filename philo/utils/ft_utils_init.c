/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:01:32 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/15 12:16:30 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_option	*ft_init_opt(char **argv)
{
	t_option	*opt;

	opt = malloc(sizeof(t_option));
	if (!opt)
	{
		ft_putstr_fd("ft_init_opt error.\n", 2);
		return (0);
	}
	opt->number_of_philo = ft_atoi(argv[1]);
	opt->time_to_die = ft_atoi(argv[2]);
	opt->time_to_eat = ft_atoi(argv[3]);
	opt->time_to_sleep = ft_atoi(argv[4]);
	if (!argv[5])
		opt->must_eat = 0;
	else
		opt->must_eat = ft_atoi(argv[5]);
	if (ft_set_opt_mutex(opt) == 0)
	{
		free(opt);
		ft_putstr_fd("ft_set_opt_mutex error.\n", 2);
		return (0);
	}
	return (opt);
}

t_philo	*ft_init_philo_list_sub(t_option *opt, int i)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	philo->philo_num = i;
	philo->opt = opt;
	philo->l_fork = i;
	philo->r_fork = (i + 1) % opt->number_of_philo;
	philo->last_eat = 0;
	philo->state_eat = 0;
	philo->black_hole = 0;
	philo->eat_count = 0;
	if (ft_set_philo_mutex(philo) == 0)
		return (0);
	return (philo);
}

t_philo	**ft_init_philo_list(t_option *opt)
{
	t_philo	**philo_list;
	int		i;

	philo_list = malloc(sizeof(t_philo *) * opt->number_of_philo);
	if (!philo_list)
	{
		free(opt);
		return (0);
	}
	i = 0;
	while (i < opt->number_of_philo)
	{
		philo_list[i] = ft_init_philo_list_sub(opt, i);
		if (!philo_list[i])
		{
			ft_free_philo_list(philo_list, i);
			ft_putstr_fd("ft_set_philo_mutex error.\n", 2);
			return (0);
		}
		i++;
	}
	return (philo_list);
}

t_total	*ft_init_total(t_option *opt, t_philo **philo_list)
{
	t_total	*total;

	total = malloc(sizeof(t_total));
	if (!total)
	{
		ft_free_philo_list(philo_list, opt->number_of_philo);
		free(opt);
		ft_putstr_fd("ft_init_total error.\n", 2);
		return (0);
	}
	total->opt = opt;
	total->philo_list = philo_list;
	return (total);
}
