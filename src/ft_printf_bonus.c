/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:43:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/09 18:43:06 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_arg	arg;
	char	*buf;
	char	*var;

	va_start(ap, format);
	buf = ft_strdup(format);
	var = ft_strchr(buf, '%');
	arg.printed = 0;
	if (var == NULL)
		arg.printed = ft_strlen(buf);
	while (var != NULL)
	{
		arg.printed = var - buf;
		if (arg_parser(&arg, &var, ap) || format_current(&arg, &buf, var, ap))
		{
			arg.printed = FT_PRINTF_ERROR;
			break ;
		}
		var = ft_strchr(buf + arg.printed, '%');
	}
	arg.printed += ft_strlen(buf + arg.printed);
	va_end(ap);
	return (print_buffer(&buf, &arg));
}
