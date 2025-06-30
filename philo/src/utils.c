/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:37:32 by yfaustin          #+#    #+#             */
/*   Updated: 2025/06/30 16:11:46 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return ((tv.tv_sec * 1000LL) + tv.tv_usec / 1000);
}

void	ft_putstr_fd(const char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_atopll(const char *str, long long *res)
{
	int			i;
	long long	tmp;

	i = 0;
	tmp = 0;
	if (!str || !str[i])
		return (0);
	while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	if (str[i] == '+')
		i++;
	if (!ft_is_digit(str[i]))
		return (0);
	while (str[i] && ft_is_digit(str[i]))
	{
		if (tmp > (LLONG_MAX - (str[i] - '0')) / 10)
			return (0);
		tmp = tmp * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	if (tmp <= 0)
		return (0);
	*res = tmp;
	return (1);
}

int	ft_atopi(const char *str, int *res)
{
	int			i;
	long long	tmp;

	i = 0;
	tmp = 0;
	if (!str || !str[i])
		return (0);
	while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	if (str[i] == '+')
		i++;
	if (!ft_is_digit(str[i]))
		return (0);
	while (str[i] && ft_is_digit(str[i]))
	{
		if (tmp > (long long)(INT_MAX - (str[i] - '0')) / 10)
			return (0);
		tmp = tmp * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	if (tmp <= 0 || tmp > INT_MAX)
		return (0);
	*res = (int)tmp;
	return (1);
}
