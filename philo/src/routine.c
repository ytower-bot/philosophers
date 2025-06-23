/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:46:12 by yfaustin          #+#    #+#             */
/*   Updated: 2025/06/20 17:33:32 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	monitor(t_table *table)
{
	int	i;
	int all_have_eaten;

	while (1)
	{
		all_have_eaten = 1;
		i = -1;
		while (++i < table->args.n_of_philo)
		{
			pthread_mutex_lock(&table->meal_mutex);
			if (get_time() - table->philosophers[i].last_meal_ts > table->args.time_to_die)
			{
				print_status(&table->philosophers[i], "died");
				pthread_mutex_lock(&table->end_mutex);
				table->end_simulation = 1;
				pthread_mutex_unlock(&table->end_mutex);
				pthread_mutex_unlock(&table->meal_mutex);
				return ;
			}
			if (table->args.n_of_rounds != -1 && table->philosophers[i].meal_count < table->args.n_of_rounds)
				all_have_eaten = 0;
			pthread_mutex_unlock(&table->meal_mutex);
		}
		
		pthread_mutex_lock(&table->end_mutex);
		if (table->end_simulation)
		{
			pthread_mutex_unlock(&table->end_mutex);
			break ;
		}
		if (table->args.n_of_rounds != -1 && all_have_eaten == 1)
		{
			table->end_simulation = 1;
			pthread_mutex_unlock(&table->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->end_mutex);
		usleep(1000);
	}
}

int	start_simulation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->args.n_of_philo)
	{
		if (pthread_create(&table->philosophers[i].thread, NULL, &routine, &table->philosophers[i]) != 0)
			return (print_error("Failed creating philosopher thread"));
		i++;
	}
	monitor(table);
	i = 0;
	while (i < table->args.n_of_philo)
	{
		if (pthread_join(table->philosophers[i].thread, NULL) != 0)
			return (print_error("Failed joining philosopher thread"));
		i++;
	}
	return (1);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;

	philo = (t_philosopher *)arg;
	table = philo->table;
	if (table->args.n_of_philo == 1)
	{
		print_status(philo, "has taken a fork");
		precise_sleep(table->args.time_to_die, table);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		precise_sleep(5, philo->table);
	
	while (1)
	{
		pthread_mutex_lock(&table->end_mutex);
		if (table->end_simulation)
		{
			pthread_mutex_unlock(&table->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->end_mutex);
		philo_eat(philo);
		print_status(philo, "is sleeping");
		precise_sleep(philo->table->args.time_to_sleep, philo->table);
		print_status(philo, "is thinking");
	}
	return (NULL);
}