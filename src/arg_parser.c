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
	t_types	type;
	uint8_t	flags;
	size_t	width;
	char	*ptr;
	char	*res;

	res = NULL;
	ptr = flags_parser(var, &flags, &width);
	if (ptr == NULL)
		return (NULL);
	type = get_type(*ptr++);
	if (type == TYPE_ERROR)
		return (NULL);
	return (res);
}
