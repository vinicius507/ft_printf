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
	ZERO_PAD		= 0b00010,
	LEFT_JUSTIFY	= 0b00100,
}	t_flags;

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

/* Formats current specifier and updates buffer. */
int		format_current(t_arg *arg, char **buf, char *var, va_list ap);

/* Applies minimum field generally. */
int		apply_width(char **str, t_arg *arg);

/* Formats `int` type specifier. */
char	*format_int(t_arg *arg, va_list ap);

/* Formats `unsigned int` type specifier. */
char	*format_uint(t_arg *arg, va_list ap);

/* Applies precision for int specifier. */
int		apply_precision_int(char **str, t_arg *arg);

/* Applies minimum field width for int specifier. */
int		apply_width_int(char **str, t_arg *arg);

/* Applies precision for unsigned int specifier. */
int		apply_precision_uint(char **str, t_arg *arg);

/* Applies minimum field width for unsigned int specifier. */
int		apply_width_uint(char **str, t_arg *arg);

/* Prints the buffer and returns the number of printed characters. */
int		print_buffer(char **buf, t_arg *arg);

#endif
