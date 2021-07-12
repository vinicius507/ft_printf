/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:47:14 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/12 15:47:14 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_char(t_arg *arg, va_list ap)
{
	char	*res;

	res = ft_calloc(2, sizeof(char));
	res[0] = (unsigned char)va_arg(ap, int);
	arg->printed += 1;
	return (res);
}
