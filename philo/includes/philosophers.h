/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:56:07 by yfaustin          #+#    #+#             */
/*   Updated: 2025/06/03 12:57:09 by yfaustin         ###   ########.fr       */
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

// parser struct
typedef struct s_args
{
	int			n_of_philo;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			n_of_rouds;
	int			valid_args;
}				t_args;

// utils
int	ft_strlen(char *str);
int	check_args(t_args *args, int argc, char **argv);

// error
void	exit_error(char *message);

#endif
