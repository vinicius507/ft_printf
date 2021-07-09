/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_current.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:44:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/08 21:44:16 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_current(t_arg *arg, char **buf, char *var, va_list ap)
{
	char	*start;
	char	*end;

	start = ft_substr(*buf, 0, arg->printed);
	if (arg->type == INTEGER && arg->modifier == L_NONE)
		end = format_int(var, arg, ap);
	else
		end = ft_strdup("");
	free(*buf);
	*buf = ft_strjoin(start, end);
	if (*buf == NULL)
		return (FT_PRINTF_ERROR);
	free(start);
	free(end);
	return (0);
}
