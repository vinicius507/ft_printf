/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 08:42:32 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/06/06 08:42:32 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// FIX: NEED TO FIX arg.printed

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_arg	arg;
	char	*buf;
	char	*var;

	va_start(ap, format);
	buf = ft_strdup(format);
	var = ft_strchr(buf, '%');
	if (var != NULL)
		arg.printed = var - buf;
	else
		arg.printed = ft_strlen(buf);
	while (var != NULL)
	{
		if (arg_parser(&arg, &var, ap) || format_current(&arg, &buf, var, ap))
		{
			arg.printed = FT_PRINTF_ERROR;
			break ;
		}
		var = ft_strchr(buf + arg.printed, '%');
	}
	if (arg.printed > 0)
		ft_putstr(buf);
	va_end(ap);
	return (arg.printed);
}
