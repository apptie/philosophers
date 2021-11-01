/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:32:21 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/15 12:24:16 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_option	*opt;
	t_philo		**philo_list;
	t_total		*total;
	int			i;

	if (ft_check_opt(argc, argv) == 0)
		return (0);
	opt = ft_init_opt(argv);
	if (!opt)
		return (0);
	philo_list = ft_init_philo_list(opt);
	total = ft_init_total(opt, philo_list);
	if (ft_process_monitor(total) == 0)
		exit(1);
	ft_process_process(total);
	sem_wait(opt->sem_check_dead);
	i = 0;
	while (i < opt->number_of_philo)
		kill(philo_list[i++]->pid, SIGKILL);
	ft_free_total(total);
	exit(0);
}
