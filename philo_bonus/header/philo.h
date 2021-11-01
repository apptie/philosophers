/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 00:09:51 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/15 10:28:03 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo	t_philo;
typedef struct s_option	t_option;
typedef struct s_total	t_total;

struct s_philo
{
	pid_t				pid;
	int					philo_num;
	int					l_fork;
	int					r_fork;
	unsigned long long	last_eat;
	int					state_eat;
	unsigned long long	black_hole;
	int					eat_count;
	t_option			*opt;
	sem_t				*sem_check_behavior;
	sem_t				*sem_check_eat;
};

struct s_option
{
	int					number_of_philo;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	int					must_eat;
	unsigned long long	start_time;
	pthread_t			eat_thread;
	sem_t				*sem_fork;
	sem_t				*sem_check_dead;
	sem_t				*sem_check_write;
	sem_t				*sem_dead_write;
};

struct s_total
{
	t_option	*opt;
	t_philo		**philo_list;
};

int					ft_check_opt(int argc, char **argv);

t_option			*ft_init_opt(char **argv);
t_philo				**ft_init_philo_list(t_option *opt);
t_total				*ft_init_total(t_option *opt, t_philo **philo_list);

int					ft_set_opt_sem(t_option *opt);
int					ft_set_philo_sem(t_philo *philo);

sem_t				*ft_sem_open(char *name, int size);
char				*ft_get_sem_name(char *s, char *target, int philo_num);

int					ft_process_monitor(t_total *total);
void				ft_process_process(t_total *total);

void				*ft_monitor_eat_count(void *total_void);
void				*ft_monitor_philo(void *philo_void);

void				ft_philo_get_fork(t_philo *philo);
void				ft_philo_set_fork(t_philo *philo);
void				ft_philo_eat(t_philo *philo);

void				ft_free_philo_list(t_philo **philo_list, int target);
void				ft_free_total(t_total *total);

unsigned long long	ft_get_time(void);
void				ft_usleep(unsigned long long delay);
void				ft_print_msg(char *s, t_philo *philo);

#endif
