/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:46:12 by yfaustin          #+#    #+#             */
/*   Updated: 2025/06/06 19:46:56 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;

	philo = (t_philosopher *)arg;
	table = philo->table;

	while(!table->end_simulation)
	{
		// 1 - eating
		// lock the forks
		// update last_meal_ts
		// print status 'eating'
		// usleep through 'time to eat'
		// increase philo->meal_count
		// unlock forks
		//
		// 2 - sleep
		// print status 'sleeping'
		// usleep through 'time to sleep'
		//
		// 3 - thinking
		// print status 'thinking'
		// usleep until forks available
	}

	return (NULL);
}
