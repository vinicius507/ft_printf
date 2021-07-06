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
	ALTERNATE		= 0b00001,
	ZERO_PAD		= 0b00010,
	RIGHT_JUSTIFY	= 0b00100,
	SPACE			= 0b01000,
	PLUS			= 0b10000,
}	t_flags;

/* ft_printf length modifiers */
typedef enum e_length
{
	L_NONE,
	L_L,
	L_LL,
	L_H,
	L_HH,
}	t_length;

/* ft_printf types */
typedef enum e_types
{
	TYPE_ERROR,
	LITERAL,
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

/* Gets the type to be currently formated */
t_types	get_type(char f);

/* Frees up to three pointers. */
void	kill(void *ptr1, void *ptr2, void *ptr3);

/* Prints and frees buffer and returns number of characters printed. */
int		print_buffer(char **buf);

/* */
char	*arg_parser(char *var, va_list ap);

/* Parses the flags of the current specifier. */
uint8_t	flags_parser(char **f);

/* Parses the minimum field width of the current specifier. */
int		width_parser(char **f, va_list ap);

/* Parses the precision of the current specifier. */
int		precision_parser(char **f, va_list ap);

/* Parses the length modifier of the current specifier */
uint8_t	length_parser(char **f);

/* Parses `int` argument. */
char	*printf_int(uint8_t flags, size_t width, int arg);

#endif
