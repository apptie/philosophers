/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:15:29 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/15 11:38:53 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_argv_length(char *argv)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	if (argv[0] == '+' || argv[0] == '-')
	{
		i++;
		length--;
	}
	while (argv[i] == '0')
		i++;
	while (argv[i])
	{
		i++;
		length++;
	}
	return (length);
}

int	ft_check_num(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	if (argv[0] == '+' || argv[0] == '-')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_argv(char *argv)
{
	int			length;
	int			result;
	long long	argv_num;

	length = ft_argv_length(argv);
	result = ft_check_num(argv);
	if (!result || length > 11 || length < 0)
		return (0);
	else
	{
		argv_num = ft_atoi(argv);
		if (argv_num > 2147483647 || argv_num < 1)
			return (0);
		else
			return (1);
	}
}

int	ft_check_opt(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("arguments error.\n", 2);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (ft_check_argv(argv[i]) == 0)
		{
			ft_putstr_fd("arguments error.\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
