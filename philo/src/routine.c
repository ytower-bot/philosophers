/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:46:12 by yfaustin          #+#    #+#             */
/*   Updated: 2025/07/15 01:14:53 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/utils.h"

void	monitor(t_table *table)
{
	int	all_have_eaten;

	all_have_eaten = 1;
	while (1)
	{
		meal_check(table, &all_have_eaten);
		pthread_mutex_lock(&table->end_mutex);
		if (table->end_simulation)
		{
			pthread_mutex_unlock(&table->end_mutex);
			break ;
		}
		if (table->args.rounds != -1 && all_have_eaten == 1)
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
	int	va;

	i = 0;
	while (i < table->args.n_philo)
	{
		va = pthread_create(&table->philo[i].tid, NULL, &act, &table->philo[i]);
		if (va != 0)
			return (print_error("Failed creating philosopher thread"));
		i++;
	}
	monitor(table);
	i = 0;
	while (i < table->args.n_philo)
	{
		if (pthread_join(table->philo[i].tid, NULL) != 0)
			return (print_error("Failed joining philosopher thread"));
		i++;
	}
	if (table->args.rounds != -1)
	{
		long long timestamp = get_time() - table->start_time;
		printf("%lld All philosophers have finished eating\n", timestamp);
		fflush(stdout);
	}
	return (1);
}

static void	*lonely_philo(t_table *table)
{
	t_philosopher	*philo;

	philo = table->philo;
	if (table->args.n_philo == 1)
	{
		print_status(philo, "has taken a fork");
		precise_sleep(table->args.t_die, table);
	}
	return (NULL);
}

void	*act(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;

	philo = (t_philosopher *)arg;
	table = philo->table;
	
	if (table->args.n_philo == 1)
	{
		lonely_philo(table);
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
		
		pthread_mutex_lock(&table->end_mutex);
		if (table->end_simulation)
		{
			pthread_mutex_unlock(&table->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->end_mutex);
		
		print_status(philo, "is sleeping");
		precise_sleep(philo->table->args.t_sleep, philo->table);
		
		pthread_mutex_lock(&table->end_mutex);
		if (table->end_simulation)
		{
			pthread_mutex_unlock(&table->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->end_mutex);
		
		print_status(philo, "is thinking");
	}
	return (NULL);
}
