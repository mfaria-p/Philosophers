/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <mfaria-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:22:33 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/05/14 12:27:52 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (write(2, "Error getting time", 19), 1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_check_sleep(t_philo *philo)
{
	if (*philo->dead == 1)
		return (1);
	return (0);
}

int	ft_usleep(size_t milliseconds, t_philo *philo)
{
	size_t	start;

	start = ft_gettime();
	while ((ft_gettime() - start) < milliseconds && ft_check_sleep(philo) == 0)
		usleep(500);
	return (0);
}
