/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:06:01 by yfaustin          #+#    #+#             */
/*   Updated: 2025/06/03 19:06:08 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (!(check_args(&args, argc, argv)))
		return (1);
	printf("number of philosophers: %d\n", args.n_of_philo);
	printf("time to die: %lld\n", args.time_to_die);
	printf("time to eat: %lld\n", args.time_to_eat);
	printf("time to sleep: %lld\n", args.time_to_sleep);
	if (args.n_of_rounds != -1)
		printf("number of rounds: %d\n", args.n_of_rounds);
	return (0);
}
