/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:42:23 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/09 18:42:23 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	safe_free(void **ptr)
{
	if (*ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}

int	print_buffer(char **buf, t_arg *arg)
{
	ft_putstr(*buf);
	safe_free((void **)buf);
	return (arg->printed);
}
