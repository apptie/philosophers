/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_sem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:39:13 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/12 17:56:10 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

sem_t	*ft_sem_open(char *name, int size)
{
	return (sem_open(name, O_CREAT | O_EXCL, 0644, size));
}

char	*ft_get_sem_name(char *s, char *target, int philo_num)
{
	int	i;

	i = ft_strcpy(target, s);
	while (philo_num > 0)
	{
		target[i] = (philo_num % 10) + '0';
		philo_num /= 10;
		i++;
	}
	target[i] = 0;
	return (target);
}
