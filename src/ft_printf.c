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

	va_start(ap, format);
	buf = ft_strdup(format);
	var = ft_strchr(buf, '%');
	while (var != NULL)
	{
	}
	ft_putstr(buf);
	free(buf);
	va_end(ap);
	return (ft_strlen(buf));
}
