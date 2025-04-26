/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <mfaria-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:18:30 by mfaria-p          #+#    #+#             */
/*   Updated: 2025/04/26 16:23:29 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	num;

	i = 0;
	s = 1;
	num = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = s * (-1);
		i++;
	}
	while (nptr[i] && (nptr[i] <= '9' && nptr[i] >= '0'))
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num * s);
}

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	mutex_destroy(char *str, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (i < program->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	print_state(char *str, t_philo *philo, int id)
{
	size_t	time;
	const char *colors[] = {
        "\033[31m", // Red
        "\033[32m", // Green
        "\033[33m", // Yellow
        "\033[34m", // Blue
        "\033[35m", // Magenta
        "\033[36m", // Cyan
        "\033[37m"  // White
    };
    const char *reset_color = "\033[0m";

	pthread_mutex_lock(philo->write_lock);
	time = ft_gettime() - philo->start_time;
	if (!check_death(philo))
	printf("%sAt %zu ms, Philo %d %s%s\n", 
		colors[(id - 1) % 7], time, id, str, reset_color);
	pthread_mutex_unlock(philo->write_lock);
}

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_state("has taken a fork", philo, philo->id);
	ft_usleep(philo->time_to_die, philo);
	pthread_mutex_unlock(philo->r_fork);
	return ;
}
