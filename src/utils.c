/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:02:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/06/14 18:02:43 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	isflag(char c)
{
	if (c == '%' || c == '0' || c == '-' || c == '.' || c == '*')
		return (1);
	return (0);
}

int8_t	get_type(char f)
{
	if (f == 'd' || f == 'i')
		return (INTEGER);
	else if (f == 'p')
		return (POINTER);
	else if (f == 'u')
		return (U_INTEGER);
	else if (f == 'x')
		return (HEXA_L);
	else if (f == 'X')
		return (HEXA_U);
	return (FT_PRINTF_ERROR);
}
