/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 08:44:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/06/06 08:44:08 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define ERROR -1

/* ft_printf flags. */
typedef enum e_flags
{
	LITERAL			= 0b0000001,
	ZERO_PAD		= 0b0000010,
	RIGHT_JUSTIFY	= 0b0000100,
	PRECISION		= 0b0001000,
	PRECISION_ARG	= 0b0010000,
	ARGUMENT		= 0b0100000,
}	t_flags;

/* Write formated output to stdout. */
int	ft_printf(const char *str, ...);

/* Verify if character `c` is a type flag. */
int	istype(char c);

/* Parses the flags given to a type specifier in `ft_printf` */
int	get_flags(const char *f);

#endif
