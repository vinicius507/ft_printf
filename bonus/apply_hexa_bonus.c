/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hexa_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:46:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/12 19:46:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	apply_alternate(char **str, t_arg *arg)
{
	char	*res;

	if (!(arg->flags & ALTERNATE))
		return (0);
	res = ft_strjoin("0x", *str);
	safe_free((void **)str);
	*str = res;
	if (*str == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}
