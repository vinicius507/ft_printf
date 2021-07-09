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

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

# define FT_PRINTF_ERROR -1

/* ft_printf flags. */
typedef enum e_flags
{
	ALTERNATE		= 0b00001,
	ZERO_PAD		= 0b00010,
	LEFT_JUSTIFY	= 0b00100,
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

typedef struct s_arg
{
	uint8_t		flags;
	int			width;
	int			precision;
	t_length	modifier;
	t_types		type;
	size_t		printed;
}	t_arg;

/* Write formated output to stdout. */
int		ft_printf(const char *str, ...);

/* Frees a pointer, if not NULL, and assigns NULL to it. */
void	safe_free(void **ptr);

/* Parses the arguments of the current specifier. */
int		arg_parser(t_arg *arg, char **var, va_list ap);

/* Parses the flags of the current specifier. */
uint8_t	flags_parser(char **f);

/* Parses the minimum field width of the current specifier. */
int		width_parser(char **f, va_list ap);

/* Parses the precision of the current specifier. */
int		precision_parser(char **f, va_list ap);

/* Parses the length modifier of the current specifier */
uint8_t	length_parser(char **f);

/* Formats current specifier and updates buffer. */
int		format_current(t_arg *arg, char **buf, char *var, va_list ap);

/* Formats `int` type specifier. */
char	*format_int(t_arg *arg, va_list ap);

/* Applies precision for int specifier. */
int		apply_precision_int(char **str, long long int nbr, t_arg *arg);

/* Applies sign for int specifier. */
int		apply_sign(char **str, long long int nbr, t_arg *arg);

/* Applies minimum field width for int specifier. */
int		apply_width_int(char **str, long long int nbr, t_arg *arg);

/* Prints the buffer and returns the number of printed characters. */
int		print_buffer(char **buf, t_arg *arg);

#endif