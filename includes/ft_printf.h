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
# include <stdint.h>

# define FT_PRINTF_ERROR -1

/* ft_printf flags. */
typedef enum e_flags
{
	LITERAL			= 0b00000001,
	ZERO_PAD		= 0b00000010,
	RIGHT_JUSTIFY	= 0b00000100,
	PRECISION		= 0b00001000,
	PRECISION_ARG	= 0b00010000,
	ARGUMENT		= 0b00100000,
}	t_flags;

typedef enum e_types
{
	CHARACTER,
	STRING,
	POINTER,
	INTEGER,
	U_INTEGER,
	HEXA_L,
	HEXA_U
}	t_types;

/* Write formated output to stdout. */
int		ft_printf(const char *str, ...);

/* Verify if character `c` is a type specifier. */
int		istype(char c);

/* Verify if character `c` is a flag. */
int		isflag(char c);

/* Gets the type to be currently formated */
int8_t	get_type(char f);

/* Gets the current flag */
t_flags	get_flag(char f, uint8_t reset);

/* Parses the flags and width for the current specifier. */
uint8_t	flags_parser(char *f, size_t *width);

#endif
