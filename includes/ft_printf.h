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
	TYPE_ERROR,
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
t_types	get_type(char f);

/* */
char	*arg_parser(char *var, va_list ap);

/* Parses the flags and width for the current specifier. On success, returns
 * the a pointer to the character after the last flag. On failure returns NULL.
 * */
char	*flags_parser(char *f, uint8_t *flags, size_t *width);

/* Parses `int` argument. */
char	*printf_int(uint8_t flags, size_t width, int arg);

#endif
