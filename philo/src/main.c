/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:06:01 by yfaustin          #+#    #+#             */
/*   Updated: 2025/06/05 20:32:56 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (!(check_args(&table.args, argc, argv)))
		return (1);
	printf("number of philosophers: %d\n", table.args.n_of_philo);
	printf("time to die: %lld\n", table.args.time_to_die);
	printf("time to eat: %lld\n", table.args.time_to_eat);
	printf("time to sleep: %lld\n", table.args.time_to_sleep);
	if (table.args.n_of_rounds != -1)
		printf("number of rounds: %d\n", table.args.n_of_rounds);
	if (!init(&table, argc, argv))
		return (1);
	printf("Simulation started\n");
	return (0);
}
