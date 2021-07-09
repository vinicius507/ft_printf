/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:58:03 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/06 14:58:03 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_parser(char **f, va_list ap)
{
	char	*ptr;
	int		width;

	ptr = *f;
	width = 0;
	if (*ptr && ft_isdigit(*ptr))
	{
		width = ft_atoi(ptr);
		while (*ptr && ft_isdigit(*ptr))
			ptr++;
	}
	else if (*ptr && *ptr == '*')
	{
		width = va_arg(ap, int);
		ptr++;
	}
	*f = ptr;
	return (width);
}
