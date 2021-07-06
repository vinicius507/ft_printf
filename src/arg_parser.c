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

char	*arg_parser(char *var, va_list ap)
{
	uint8_t	flags;
	int		width;
	int		precision;
	uint8_t	length;
	t_types	type;

	var += 1;
	flags = flags_parser(&var);
	width = width_parser(&var, ap);
	precision = precision_parser(&var, ap);
	length = length_parser(&var);
	type = get_type(*var);
	return (NULL);
}
