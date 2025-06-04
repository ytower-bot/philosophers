/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:56:07 by yfaustin          #+#    #+#             */
/*   Updated: 2025/06/03 23:05:56 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// libs
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// variables
# define INT_MAX 2147483647
# define LLONG_MAX 9223372036854775807

// arguments
typedef struct 	s_args
{
	int			n_of_philo;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			n_of_rounds;
	int			valid_args;
}				t_args;

// create a status struct with enum and a struct that will be the table

// philosopher

typedef struct 			s_philosopher
{
	int					id;
	pthread_t			thread;
	long long			last_meal_ts;
	int					meal_count;

	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;

	struct s_table		*table;
}						t_philosopher;

// utils
int		ft_isdigit(int c);
int		ft_atopi(const char *str, int *res);
int		ft_atopll(const char *str, long long *res);
void	ft_putstr_fd(const char *str, int fd);

// check args
int	check_args(t_args *args, int argc, char **argv);

// error
int	print_error(char *message);

#endif
