/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:06:01 by yfaustin          #+#    #+#             */
/*   Updated: 2025/06/03 15:08:36 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (!(check_args(&args, argc, argv)))
		return (1);
	printf("got here\n");
	if (args.n_of_rounds != -1)
		printf("n_of_rounds: %d\n", args.n_of_rounds);
	return (0);
}
