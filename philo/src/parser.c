/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:33:58 by yfaustin          #+#    #+#             */
/*   Updated: 2025/06/06 19:25:40 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	init_args(t_args *args)
{
	args->n_of_philo = 0;
	args->time_to_die = 0;
	args->time_to_eat = 0;
	args->time_to_sleep = 0;
	args->n_of_rounds = -1;
	args->valid_args = 0;
}

int	parse_args(t_args *args, int argc, char **argv)
{
	init_args(args);
	if (argc != 5 && argc != 6)
		return (print_error("Invalid number of arguments"));
	if (!ft_atopi(argv[1], &args->n_of_philo) || args->n_of_philo == 0)
		return (print_error("Invalid n_of_philo"));
	if (!ft_atopll(argv[2], &args->time_to_die))
		return (print_error("Invalid <time_to_die>"));
	if (!ft_atopll(argv[3], &args->time_to_eat))
		return (print_error("Invalid <time_to_eat>"));
	if (!ft_atopll(argv[4], &args->time_to_sleep))
		return (print_error("Invalid <time_to_sleep>"));
	if (argc == 6)
	{
		if (!ft_atopi(argv[5], &args->n_of_rounds))
			return (print_error("Invalid <n_of_rounds>"));
	}
	args->valid_args = 1;
	return (1);
}
