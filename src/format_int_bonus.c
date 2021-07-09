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

static int	get_nbr(t_arg *arg, long long int n)
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

static char	*get_nbr_str(t_arg *arg, long long int n)
{
	char	*nbr;
	char	*temp;

	if (arg->modifier == L_NONE)
		nbr = ft_itoa((int)n);
	else if (arg->modifier == L_L)
		nbr = ft_ltoa((long int)n);
	else if (arg->modifier == L_LL)
		nbr = ft_lltoa((long long int)n);
	else if (arg->modifier == L_H)
		nbr = ft_itoa((short int)n);
	else
		nbr = ft_itoa((char)n);
	if (n < 0)
	{
		temp = ft_substr(nbr, 1, ft_strlen(nbr));
		safe_free((void **)&nbr);
		nbr = temp;
	}
	return (nbr);
}

char	*format_int(t_arg *arg, va_list ap)
{
	int				nbr;
	char			*nbr_str;

	nbr = get_nbr(arg, va_arg(ap, long long int));
	nbr_str = get_nbr_str(arg, nbr);
	if (nbr_str == NULL)
		return (NULL);
	if (apply_precision_int(&nbr_str, nbr, arg))
		return (NULL);
	if ((arg->width > (int)ft_strlen(nbr_str) && arg->precision >= 0)
		|| (arg->width * -1 > (int)ft_strlen(nbr_str) && arg->precision >= 0))
	{
		if (apply_sign(&nbr_str, nbr, arg)
			|| apply_width_int(&nbr_str, nbr, arg))
			return (NULL);
	}
	else
	{
		if (apply_width_int(&nbr_str, nbr, arg)
			|| apply_sign(&nbr_str, nbr, arg))
			return (NULL);
	}
	arg->printed += ft_strlen(nbr_str);
	return (nbr_str);
}
