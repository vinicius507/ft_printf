/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:43:04 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/06 17:43:04 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t	length_parser(char **f)
{
	char		*ptr;
	t_length	length;

	ptr = *f;
	length = L_NONE;
	if (!ft_strncmp(ptr, "ll", 2))
	{
		length = L_LL;
		ptr++;
	}
	else if (*ptr == 'l')
		length = L_L;
	else if (!ft_strncmp(ptr, "hh", 2))
	{
		length = L_HH;
		ptr++;
	}
	else if (*ptr == 'h')
		length = L_H;
	*f = ++ptr;
	return (length);
}
