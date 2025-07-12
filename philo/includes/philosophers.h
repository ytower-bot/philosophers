/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:56:07 by yfaustin          #+#    #+#             */
/*   Updated: 2025/07/12 16:37:30 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// libs
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

// variables
# define INT_MAX 2147483647
# define LLONG_MAX 9223372036854775807

// arguments
typedef struct s_args
{
	int			n_of_philo;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			n_of_rounds;
	int			valid_args;
}	t_args;

// status
typedef enum e_status
{
	THINKING,
	HUNGRY,
	EATING,
	SLEEPING,
	DEAD
}	t_status;

// philosopher
typedef struct s_philosopher
{
	int					id;
	pthread_t			thread;
	t_status			status;
	long long			last_meal_ts;
	int					meal_count;

	pthread_mutex_t		*lfork;
	pthread_mutex_t		*rfork;

	struct s_table		*table;
}	t_philosopher;

// table
typedef struct s_table
{
	t_args			args;
	long long		start_time;
	int				end_simulation;
	t_philosopher	*philo;

	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	end_mutex;

}	t_table;

// routine
int		start_simulation(t_table *table);
void	*routine(void *arg);

// routine utils
void	philo_eat(t_philosopher *philo);

// init
int		init(t_table *table, int argc, char **argv);
int		init_mutexes(t_table *table);
int		init_philo(t_table *table);

// parser
int		parse_args(t_args *args, int argc, char **argv);

// error
int		print_error(char *message);

#endif
