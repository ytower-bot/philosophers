/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:18:47 by yfaustin          #+#    #+#             */
/*   Updated: 2025/06/30 21:07:03 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philosophers.h"

// utils
int			ft_isdigit(int c);
int			ft_atopi(const char *str, int *res);
int			ft_atopll(const char *str, long long *res);
void		ft_putstr_fd(const char *str, int fd);
long long	get_time(void);

// mutex utils
void		precise_sleep(long long ms, t_table *table);
void		print_status(t_philosopher *philo, const char *status);
void		fclean(t_table *table);

// monitor utils
void	meal_check(t_table *table, int *all_have_eaten);

#endif
