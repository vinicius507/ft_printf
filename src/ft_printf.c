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
	char	*var;
	char	*buf;
	char	*temp;

	va_start(ap, format);
	buf = NULL;
	var = ft_strchr(format, '%');
	while (var != NULL)
	{
		if (buf == NULL)
			temp = ft_substr(format, 0, var - format);
		else
			temp = ft_strnjoin(buf, format, var - format);
	}
	va_end(ap);
	return (ft_strlen(buf));
}
