/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:46:01 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/15 12:12:53 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_philo_list(t_philo **philo_list, int target)
{
	int	i;

	i = 0;
	while (i < target)
	{
		free(philo_list[i]);
		i++;
	}
	free(philo_list);
}

void	ft_free_total(t_total *total)
{
	ft_free_philo_list(total->philo_list, total->opt->number_of_philo);
	free(total->opt);
	free(total);
}
