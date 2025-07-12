/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:42:55 by yfaustin          #+#    #+#             */
/*   Updated: 2025/07/12 16:38:02 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/utils.h"
#include <pthread.h>

static void	free_philo(t_table *table)
{
	int	i;

	if (table->forks)
	{
		i = 0;
		while (i < table->args.n_of_philo)
			pthread_mutex_destroy(&table->forks[i++]);
		free(table->forks);
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->meal_mutex);
	pthread_mutex_destroy(&table->end_mutex);
}

int	init(t_table *table, int argc, char **argv)
{
	int	i;

	table->forks = NULL;
	table->philo = NULL;
	if (!parse_args(&table->args, argc, argv))
		return (0);
	if (!init_mutexes(table))
		return (0);
	if (!init_philo(table))
		return (free_philo(table), 0);
	table->end_simulation = 0;
	table->start_time = get_time();
	if (table->start_time == -1)
		return (fclean(table), print_error("Failed to get system time"));
	i = 0;
	while (i < table->args.n_of_philo)
		table->philo[i++].last_meal_ts = table->start_time;
	return (1);
}

int	init_mutexes(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->args.n_of_philo);
	if (!table->forks)
		return (print_error("Forks memory allocation failed"));
	i = 0;
	while (i < table->args.n_of_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&table->forks[i]);
			free(table->forks);
			return (print_error("Fork's mutex initialization failed"));
		}
		i++;
	}
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (print_error("print_mutex initialization failed"));
	if (pthread_mutex_init(&table->meal_mutex, NULL) != 0)
		return (print_error("meal_mutex initialization failed"));
	if (pthread_mutex_init(&table->end_mutex, NULL) != 0)
		return (print_error("end_mutex initialization failed"));
	return (1);
}

int	init_philo(t_table *table)
{
	int	i;

	table->philo = malloc(sizeof(t_philosopher) * table->args.n_of_philo);
	if (!table->philo)
		return (print_error("Philosophers memory allocation failed"));
	i = 0;
	while (i < table->args.n_of_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].meal_count = 0;
		table->philo[i].table = table;
		table->philo[i].lfork = &table->forks[i];
		table->philo[i].rfork = &table->forks[(i + 1) % table->args.n_of_philo];
		i++;
	}
	return (1);
}
