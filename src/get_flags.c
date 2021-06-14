/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:10:49 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/06/14 18:10:49 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_flags(const char *f)
{
	int	flags;

	if (*f == '%')
		return (LITERAL);
	flags = 0;
	while (*f && !istype(*f))
	{
		if (*f == '0')
			flags |= ZERO_PAD;
		else if (*f == '-')
			flags |= RIGHT_JUSTIFY;
		else if (*f == '.')
		{
			flags |= PRECISION;
			if (*(f + 1) == '*' && *f++)
				flags |= PRECISION_ARG;
		}
		else if (*f == '*')
			flags |= ARGUMENT;
		f++;
	}
	return (flags);
}
