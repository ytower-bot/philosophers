/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:46:12 by yfaustin          #+#    #+#             */
/*   Updated: 2025/06/09 21:10:50 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <pthread.h>

void	*routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
		precise_sleep(5, philo->table);
	while(!philo->table->end_simulation)
	{
		philo_eat(philo);
		print_status(philo, "is sleeping");
		precise_sleep(philo->table->args.time_to_sleep, philo->table);
		print_status(philo, "is thinking");
	}
	return (NULL);
}
