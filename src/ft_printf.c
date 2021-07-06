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

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*buf;
	char	*var;
	char	*start;
	char	*end;

	va_start(ap, format);
	buf = ft_strdup(format);
	var = ft_strchr(buf, '%');
	while (var != NULL)
	{
		start = ft_substr(buf, 0, var - buf);
		end = arg_parser(var + 1, ap);
		if (start == NULL || end == NULL)
		{
			kill(start, end, buf);
			return (FT_PRINTF_ERROR);
		}
		free(buf);
		buf = ft_strjoin(start, end);
		kill(start, end, NULL);
		var = ft_strchr(buf, '%');
	}
	va_end(ap);
	return (print_buffer(&buf));
}
