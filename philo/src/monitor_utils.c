/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:39:01 by yfaustin          #+#    #+#             */
/*   Updated: 2025/07/12 17:47:26 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/utils.h"

void	meal_check(t_table *table, int *all_have_eaten)
{
	int	i;

	*all_have_eaten = 1;
	i = -1;
	while (++i < table->args.n_philo)
	{
		pthread_mutex_lock(&table->meal_mutex);
		if (get_time() - table->philo[i].last_meal_ts > table->args.t_die)
		{
			print_status(&table->philo[i], "died");
			pthread_mutex_lock(&table->end_mutex);
			table->end_simulation = 1;
			pthread_mutex_unlock(&table->end_mutex);
			pthread_mutex_unlock(&table->meal_mutex);
			return ;
		}
		if (table->args.rounds != -1)
			if (table->philo[i].meal_count < table->args.rounds)
				*all_have_eaten = 0;
		pthread_mutex_unlock(&table->meal_mutex);
	}
}
