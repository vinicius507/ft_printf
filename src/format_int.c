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

static char	*get_nbr_str(int nbr)
{
	char	*res;
	char	*temp;

	res = ft_itoa(nbr);
	if (nbr >= 0)
		return (res);
	temp = ft_substr(res, 1, ft_strlen(res));
	safe_free((void **)&res);
	res = temp;
	return (res);
}

char	*format_int(t_arg *arg, va_list ap)
{
	int				nbr;
	char			*nbr_str;

	nbr = va_arg(ap, int);
	nbr_str = get_nbr_str(nbr);
	if (nbr_str == NULL)
		return (NULL);
	if (apply_precision_int(&nbr_str, nbr, arg))
		return (NULL);
	if (arg->precision >= 0 && (arg->width > (int)ft_strlen(nbr_str)
			|| arg->width * -1 > (int)ft_strlen(nbr_str)))
	{
		if (apply_sign(&nbr_str, nbr)
			|| apply_width_int(&nbr_str, nbr, arg))
			return (NULL);
	}
	else
	{
		if (apply_width_int(&nbr_str, nbr, arg)
			|| apply_sign(&nbr_str, nbr))
			return (NULL);
	}
	arg->printed += ft_strlen(nbr_str);
	return (nbr_str);
}
