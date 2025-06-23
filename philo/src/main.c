/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:06:01 by yfaustin          #+#    #+#             */
/*   Updated: 2025/06/20 17:34:30 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <pthread.h>

int	main(int argc, char **argv)
{
	t_table	table;

	if (!init(&table, argc, argv))
		return (1);
	if (!start_simulation(&table))
	{
		fclean(&table);
		return (1);
	}
	fclean(&table);
	return (0);
}
