/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 22:00:12 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/08 22:00:12 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	get_nbr(t_arg *arg, long long int n)
{
	long long int	nbr;

	if (arg->modifier == L_NONE)
		nbr = (int)n;
	else if (arg->modifier == L_L)
		nbr = (long int)n;
	else if (arg->modifier == L_LL)
		nbr = (long long int)n;
	else if (arg->modifier == L_H)
		nbr = (short int)n;
	else
		nbr = (char)n;
	return (nbr);
}

char	*format_int(char *var, t_arg *arg, va_list ap)
{
	char			*res;
	long long int	nbr;

	nbr = get_nbr(arg, va_arg(ap, long long int));
	return (res);
}
