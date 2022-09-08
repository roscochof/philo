/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:23:14 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/08 16:50:54 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_philo.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void	ft_check_arg_int(char **argv, t_control *control)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				control->error = 2;
			j++;
		}
		i++;
	}
}

void	ft_print_errors(t_control	*control)
{
	if (control->error == 1)
		write(2, "Error\nInvalid arg number\n", 26);
	else if (control->error == 2)
		write(2, "Error\nYou must write numeric args\n", 33);
	else if (control->error == 3)
		write(2, "Error\nToo big / Negative num arg\n", 33);
	else if (control->error == 4)
		write(2, "Error\nAt least one philosopher\n", 31);
	if (control->error != 0)
		exit(0);
}

void	ft_check_max_int(char **argv, t_control *control)
{
	int		i;
	long	num;

	i = 1;
	num = 0;
	while (argv[i])
	{
		num = ft_philo_atoi(argv[i]);
		if (num < 0 || num > INT_MAX)
			control->error = 3;
		if (i == 1 && num == 0)
			control->error = 4;
		i++;
	}
}

void	ft_checks(int argc, char **argv, t_control *control)
{
	if (argc < 5 || argc > 6)
		control->error = 1;
	ft_check_arg_int(argv, control);
	ft_check_max_int(argv, control);
	ft_print_errors(control);
}

void	ft_check_loop(t_philo *ph, pthread_mutex_t *mutex)
{
	int		i;
	long	time;

	while (1)
	{
		i = 0;
		while (i < ph[0].ph_nb)
		{
			if (ph[i].limit_time < ft_get_time())
			{
				pthread_mutex_lock(mutex);
				time = ft_get_time() - ph[i].start;
				printf("\033[31m" "%ld %d died\n" "\033[0m", time, ph[i].index);
				//HAY QUE TERMINAR ESTA PARTE
				free (ph);
				exit(0);
			}
			i++;
		}
	}
}
