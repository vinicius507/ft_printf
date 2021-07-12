/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:04:14 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/12 13:04:14 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_uint(t_arg *arg, va_list ap)
{
	unsigned int	nbr;
	char			*nbr_str;

	nbr = va_arg(ap, unsigned int);
	nbr_str = ft_uitoa(nbr);
	if (nbr_str == NULL)
		return (NULL);
	if (apply_precision_int(&nbr_str, arg)
		|| apply_width_int(&nbr_str, arg))
		return (NULL);
	arg->printed += ft_strlen(nbr_str);
	return (nbr_str);
}
