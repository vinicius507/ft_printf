/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:44:36 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/06/25 21:44:36 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_types	get_type(char f)
{
	if (f == '%')
		return (LITERAL);
	else if (f == 'd' || f == 'i')
		return (INTEGER);
	else if (f == 'u')
		return (U_INTEGER);
	else if (f == 'c')
		return (CHARACTER);
	else if (f == 's')
		return (STRING);
	else if (f == 'p')
		return (POINTER);
	else if (f == 'x')
		return (HEXA_L);
	else if (f == 'X')
		return (HEXA_U);
	return (TYPE_ERROR);
}

int	arg_parser(t_arg *arg, char *var, va_list ap)
{
	var += 1;
	arg->flags = flags_parser(&var);
	arg->width = width_parser(&var, ap);
	arg->precision = precision_parser(&var, ap);
	arg->modifier = length_parser(&var);
	arg->type = get_type(*var);
	if (arg->type == TYPE_ERROR)
		return (FT_PRINTF_ERROR);
	return (0);
}
