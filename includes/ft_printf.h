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

# ifdef __linux__
#  define NULL_STR "(nil)"
# elif defined(__APPLE__)
#  define NULL_STR "0x0"
# else
#  define NULL_STR "(null)"
# endif

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
	t_types		type;
	ssize_t		printed;
}	t_arg;

/* Write formated output to stdout. */
int		ft_printf(const char *str, ...);

/* Frees a pointer, if not NULL, and assigns NULL to it. */
void	safe_free(void **ptr);

/* Parses the arguments of the current specifier. */
int		arg_parser(t_arg *arg, char **var);

/* Formats current specifier and updates buffer. */
int		format_current(t_arg *arg, char **buf, char *var, va_list ap);

/* Formats `int` type specifier. */
char	*format_int(t_arg *arg, va_list ap);

/* Formats `unsigned int` type specifier. */
char	*format_uint(t_arg *arg, va_list ap);

/* Formats `unsigned hexa` type specifier. */
char	*format_hexa(t_arg *arg, va_list ap);

/* Formats `str` type specifier. */
char	*format_str(t_arg *arg, va_list ap);

/* Formats `char` type specifier. */
char	*format_char(t_arg *arg, va_list ap);

/* Formats `%` type specifier. */
char	*format_literal(t_arg *arg);

/* Formats `void *` type specifier. */
char	*format_ptr(t_arg *arg, va_list ap);

/* Prints the buffer and returns the number of printed characters. */
int		print_buffer(char **buf, t_arg *arg);

#endif
