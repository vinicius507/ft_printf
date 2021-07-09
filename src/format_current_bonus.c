/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_current_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:42:35 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/09 18:42:35 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*get_formated_str(t_arg *arg, va_list ap)
{
	char	*formated;

	formated = NULL;
	if (arg->type == INTEGER)
		formated = format_int(arg, ap);
	return (formated);
}

int	format_current(t_arg *arg, char **buf, char *var, va_list ap)
{
	int		printed;
	char	*start;
	char	*formated;
	char	*temp;
	char	*temp2;

	printed = arg->printed;
	start = ft_memjoin(*buf, "", printed, 1);
	temp2 = ft_strdup(var);
	safe_free((void **)buf);
	if (start == NULL)
		return (FT_PRINTF_ERROR);
	formated = get_formated_str(arg, ap);
	temp = ft_memjoin(start, formated, printed, arg->printed - printed + 1);
	safe_free((void **)&start);
	safe_free((void **)&formated);
	safe_free((void **)buf);
	*buf = ft_memjoin(temp, temp2, arg->printed, ft_strlen(temp2) + 1);
	safe_free((void **)&temp);
	safe_free((void **)&temp2);
	return (0);
}
