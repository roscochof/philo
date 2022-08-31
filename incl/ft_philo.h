/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:25:43 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/31 15:08:22 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include "ft_control.h"
# include "ft_sleep.h"
# include "libft.h"

/*----		BORRAR			----*/
void	ft_print_ctr(t_control *control);

/*----		ft_checks		----*/
void	ft_checks(int argc, char **argv, t_control *control);

#endif