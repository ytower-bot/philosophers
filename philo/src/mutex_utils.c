/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:09:12 by yfaustin          #+#    #+#             */
/*   Updated: 2025/06/30 20:14:03 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/utils.h"

void	print_status(t_philosopher *philo, const char *status)
{
	long long	timestamp;

	pthread_mutex_lock(&philo->table->print_mutex);
	pthread_mutex_lock(&philo->table->end_mutex);
	if (!philo->table->end_simulation)
	{
		timestamp = get_time() - philo->table->start_time;
		printf("%lld %d %s\n", timestamp, philo->id, status);
	}
	pthread_mutex_unlock(&philo->table->end_mutex);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	precise_sleep(long long ms, t_table *table)
{
	long long	start;
	long long	elapsed;

	start = get_time();
	if (start == -1)
		return ;
	while (1)
	{
		elapsed = get_time() - start;
		if (elapsed == -1 || elapsed >= ms)
			break ;
		pthread_mutex_lock(&table->end_mutex);
		if (table->end_simulation)
		{
			pthread_mutex_unlock(&table->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->end_mutex);
		usleep(500);
	}
}

void	fclean(t_table *table)
{
	int	i;

	if (!table)
		return ;
	if (table->forks)
	{
		i = 0;
		while (i < table->args.n_of_philo)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
	}
	pthread_mutex_destroy(&table->meal_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->end_mutex);
	if (table->philo)
		free(table->philo);
}
