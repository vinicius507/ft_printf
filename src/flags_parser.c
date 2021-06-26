/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:35:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/06/23 10:35:16 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_width(char **f_ptr)
{
	size_t	len;
	size_t	width;

	len = 1;
	while (*(*f_ptr + len) && ft_isdigit(*(*f_ptr + len)))
		len++;
	width = ft_atoi(*f_ptr);
	*f_ptr += len;
	return (width);
}

static t_flags	get_flag(char f, uint8_t reset)
{
	static t_flags	flag;

	if (reset)
		flag = 0;
	if (f == '%')
		flag = LITERAL;
	else if (f == '0')
		flag = ZERO_PAD;
	else if (f == '-')
		flag = RIGHT_JUSTIFY;
	else if (f == '.')
		flag = PRECISION;
	else if (f == '*')
	{
		if (flag == PRECISION)
			flag = PRECISION_ARG;
		else
			flag = ARGUMENT;
	}
	return (flag);
}

char	*flags_parser(char *f, uint8_t *flags, size_t *width)
{
	char	*f_ptr;

	f_ptr = f;
	*width = 0;
	flags = 0;
	while (*f_ptr && !istype(*f_ptr))
	{
		if (isflag(*f_ptr))
		{
			*flags += get_flag(*f_ptr, f_ptr == f);
			f_ptr++;
		}
		else if (ft_isdigit(*f_ptr))
		{
			*width = get_width(&f_ptr);
			get_flag(0, 1);
		}
		else
			return (NULL);
	}
	return (f_ptr);
}
