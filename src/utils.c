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

t_types	get_type(char f)
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

void	kill(void *ptr1, void *ptr2, void *ptr3)
{
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	if (ptr3)
		free(ptr3);
}

int	print_buffer(char **buf)
{
	size_t	size;

	if (*buf == NULL)
		return (FT_PRINTF_ERROR);
	size = ft_strlen(*buf);
	ft_putstr(*buf);
	free(*buf);
	return (size);
}
