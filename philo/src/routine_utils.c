/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:37:28 by yfaustin          #+#    #+#             */
/*   Updated: 2025/07/12 18:39:15 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/utils.h"

static void	eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->meal_mutex);
	philo->last_meal_ts = get_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->table->meal_mutex);
	print_status(philo, "is eating");
	precise_sleep(philo->table->args.t_eat, philo->table);
}

void	philo_eat(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->lfork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->rfork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->rfork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->lfork);
		print_status(philo, "has taken a fork");
	}
	eat(philo);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(philo->lfork);
	}
	else
	{
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
	}
}
